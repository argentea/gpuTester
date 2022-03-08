#include <iostream>
#include "database.h"


using namespace std;

int main(){
	using namespace FLATARRAY;
	cout << "This is flatArray test\n";

	int testSize = 1024*1024*1024;

	FlatArray fatest;
	fatest.init(testSize);
	return 0;
}
