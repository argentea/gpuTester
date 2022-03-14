#include "generator.h"

__global__ void __launch_bounds__(1024)
incSegGen(tValue* dv_ptr, tSize size, tSize step){
	const int threadId = threadIdx.x;
	const int threadNum = blockDim.x;
	const int blockId = blockIdx.x;
	const int blockNum = gridDim.x;


	int tsize = step;
	int bucket_num = size/step + 1;
	for(int i = blockId; i < bucket_num; i += blockNum){
		if(step * (i + 1) > size){
			tsize = size - step*i;
		}
		for(int j = threadId; j < tsize; j += threadNum){
			dv_ptr[i*step + j] = i;
		}
	}
	__syncthreads();
}
