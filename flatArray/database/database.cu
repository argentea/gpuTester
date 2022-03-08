#include <cuda_runtime.h>
#include <cuda_profiler_api.h>
#include "database.h"
#include "utils.h"

namespace FLATARRAY{

void FlatArray::dinit(){
	gpuErrchk(cudaMalloc((void **)&dv_ptr, size*sizeof(tValue)));
}

void FlatArray::dToH(){
	gpuErrchk(cudaMemcpy(hv_ptr, dv_ptr, size*sizeof(tValue), cudaMemcpyDeviceToHost));
}

void FlatArray::hTod(){
	gpuErrchk(cudaMemcpy(dv_ptr, hv_ptr, size*sizeof(tValue), cudaMemcpyHostToDevice));
}


};
