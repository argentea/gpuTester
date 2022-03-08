#include "dynamicParallelKernel.h"

namespace FADPKERNEL{

FaDPSolver::FaDPSolver(tValue* dv_ptr, tSize size):dv_ptr(dv_ptr), size(size){

}

void FaDPSolver::solve(){

}

__global__ void dynamicParallelKernel(tValue* dv_ptr, tSize size, tSize step_size){

}


__global__ void __launch_bounds__(1024)
dynamicParallelKernelChild(tValue* dst_ptr, tValue* src_ptr, tSize size){
	const int threadId = threadIdx.x;
	const int threadNum = blockDim.x;
	for(int i = threadId; i < size; i+= threadNum){
		dst_ptr[i] += src_ptr[i];
	}
	return;
}

};
