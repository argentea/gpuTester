#pragma once
#include"controller.h"
#include<fstream>

namespace FLATARRAY {

class FlatArray {
public:
	FlatArray();

	tValue* getDevicePtr();
	tValue* getHostPtr();

	void init(tSize isize);
	void clean();

	tSize getSize();
	
	void dToH();
	void hTod();

	void printHost(std::ofstream o);

private:
    tValue* dv_ptr;
    tValue* hv_ptr;

	tSize size;

	void dinit();
};

};
