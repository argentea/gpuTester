#include <iostream>
#include "database.h"
#include "dynamicParallelKernel.h"


using namespace std;

int main(){
	using namespace FLATARRAY;
	using namespace FADPKERNEL;
	cout << "This is flatArray test\n";

	int testSize = 1024*1024*1024;

	FlatArray fatest;
	fatest.init(testSize);

	FaDPSolver solver(fatest.getDevicePtr(), fatest.getSize());
	solver.solve();
	return 0;
}
