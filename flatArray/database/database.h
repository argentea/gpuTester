#pragma once
#include"controller.h"

namespace FLATARRAY {

class FlatArray {
public:
	FlatArray(tSize size);

	tValue* getDevicePtr();
	tValue* getHostPtr();

	void init(tSize isize);
	void clean();

	tSize getSize();
	
	void dToH();
	void hTod();

	void printHost();

private:
    tValue* dv_ptr;
    tValue* hv_ptr;

	tSize size;

	void dinit(tSize isize);
};

};
