#include <iostream>
#include <fstream>
#include "database.h"
#include "dynamicParallelKernel.h"


using namespace std;

int main(){
	using namespace FLATARRAY;
	using namespace FADPKERNEL;
	cout << "This is flatArray test\n";

	int testSize = 1024*1024*1024;

	FlatArray fatest;
	pTime(fatest.init(testSize));

	FaDPSolver solver(fatest.getDevicePtr(), fatest.getSize());
	pTime(solver.solve());
	
	fatest.dToH();
	ofstream initTestFile;
	initTestFile.open("./initTest");
	fatest.printCompress(initTestFile);
	initTestFile.close();
	cerr << "write initTestFile done\n";

	return 0;
}
