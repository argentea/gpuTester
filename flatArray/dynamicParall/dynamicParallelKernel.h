#pragma once
#include <cuda_runtime.h>
#include <cuda_profiler_api.h>

#include "database.h"
#include "utils.h"

/*
 * To verify synchronization for thread call and __syncthreads()
 */

namespace FADPKERNEL{
using namespace FLATARRAY;

/*
 * add the value of right array of step_size to the left iteratelly
 */
__global__ void dynamicParallelKernel(tValue* dv_ptr, tSize size, tSize step_size);

__global__ void dynamicParallelKernelChild(tValue* dst_ptr, tValue* src_ptr, tSize size);

class FaDPSolver{
public:
	FaDPSolver(tValue* dv_ptr, tSize size);
	void solve();
private:
	tValue* dv_ptr;
	tSize size;
};
};
