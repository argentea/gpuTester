#pragma once
#include"controller.h"
#include"generator.h"
#include<iostream>

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

	void printHost(std::ostream& o);

	void printCompress(std::ostream& o);

private:
    tValue* dv_ptr;
    tValue* hv_ptr;

	tSize size;

	void dinit();
};

};
