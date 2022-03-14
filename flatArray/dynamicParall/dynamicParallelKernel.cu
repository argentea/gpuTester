#include "dynamicParallelKernel.h"

namespace FADPKERNEL{

FaDPSolver::FaDPSolver(tValue* dv_ptr, tSize size):dv_ptr(dv_ptr), size(size){

}

void FaDPSolver::solve(){
	dynamicParallelKernel<<<1, 4>>>(dv_ptr, size, STEP);
	gpuErrchk( cudaDeviceSynchronize() );
}

//step size shouldn't be too small. One child kernel process step size values.
__global__ void __launch_bounds__(32)
dynamicParallelKernel(tValue* dv_ptr, tSize size, tSize step_size){
	const int threadId = threadIdx.x;
	const int threadNum = blockDim.x;

	tValue* dst_ptr;
	tValue* src_ptr;
	tSize child_size = 0;
	
	int num_launch1 = size/(2*step_size);

	for(int i = threadId; i < num_launch1; i += threadNum){
		dst_ptr = dv_ptr + 2*i*step_size;
		src_ptr = dst_ptr + step_size;
		if((2*i + 1) * step_size > size){
			child_size = size - 2*i*step_size;
		}else {
			child_size = step_size;
		}

		dynamicParallelKernelChild<<<1, 512>>>(dst_ptr, src_ptr, child_size);
	}
	cudaDeviceSynchronize();
	__syncthreads();

	int num_launch2 = (size - step_size)/(2*step_size);

	for(int i = threadId; i < num_launch2 ; i += threadNum){
		dst_ptr = dv_ptr + step_size + 2*i*step_size;
		src_ptr = dst_ptr + step_size;
		if((2*i + 1) * step_size > size - step_size){
			child_size = size - step_size - 2*i*step_size;
		}else {
			child_size = step_size;
		}
		dynamicParallelKernelChild<<<1, 512>>>(dst_ptr, src_ptr, child_size);
	}
	cudaDeviceSynchronize();
	__syncthreads();
}


__global__ void __launch_bounds__(1024)
dynamicParallelKernelChild(tValue* dst_ptr, tValue* src_ptr, tSize size){
	const int threadId = threadIdx.x;
	const int threadNum = blockDim.x;
	for(int i = threadId; i < size; i+= threadNum){
		dst_ptr[i] += src_ptr[i];
	}
	__syncthreads();
	return;
}

};
