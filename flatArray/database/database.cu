#include <cuda_runtime.h>
#include <cuda_profiler_api.h>
#include "database.h"
#include "utils.h"

namespace FLATARRAY{

void FlatArray::dinit(tSize isize){
	gpuErrchk(cudaMalloc((void **)&dv_ptr, isize*sizeof(tSize)));
}

};
