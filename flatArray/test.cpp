#include <iostream>
#include <fstream>
#include "database.h"
#include "dynamicParallelKernel.h"


using namespace std;

int main(){
	using namespace FLATARRAY;
	using namespace FADPKERNEL;
	cout << "This is flatArray test\n";

	int testSize = 512*1024*1024;

	FlatArray fatest;
	pTime(fatest.init(testSize));

	fatest.dToH();
	ofstream initTestFile;
	initTestFile.open("./initTest");
	fatest.printCompress(initTestFile);
	initTestFile.close();
	cerr << "write initTestFile done\n";

	
	FaDPSolver solver(fatest.getDevicePtr(), fatest.getSize());
	pTime(solver.solve());
	
	fatest.dToH();
	ofstream ansFile;
	ansFile.open("./ansFile");
	fatest.printCompress(ansFile);
	ansFile.close();
	cerr << "write ansFile done\n";

	return 0;
}
