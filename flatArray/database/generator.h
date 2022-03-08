#pragma once
#include <cuda_runtime.h>
#include <cuda_profiler_api.h>

#include "database.h"
#include "utils.h"

using namespace FLATARRAY;
__global__ void incSegGen(tValue* dv_ptr, tSize size, tSize step);

