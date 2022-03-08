#pragma once
#include <cuda_runtime.h>
#include <iostream>
#include<chrono>
#include<sys/wait.h>


//CUDA ERROR MACRO
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort = true) {
	if (code != cudaSuccess) {
		fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
		if (abort) {
			exit(code);
		}
	}
}

#define pTime(ans) do{\
	auto time_start = std::chrono::steady_clock::now();\
	ans;\
	auto time_end = std::chrono::steady_clock::now();\
	std::chrono::duration<double> time_solved = time_end - time_start;\
	std::cerr << "<<<\n" << #ans << " time:\t" << time_solved.count() << "s\n<<<\n";\
}while(0)
