#include"database.h"
#include<stdlib.h>

namespace FLATARRAY {

FlatArray::FlatArray(int size): size(size) {
}

tValue* FlatArray::getDevicePtr() {
    return dv_ptr;
}

tValue* FlatArray::getHostPtr() {
    return hv_ptr;
}

//subject to the input of init;
void FlatArray::init(tSize isize = 0){
	int tsize = isize;
	if(tsize == 0){
		tsize = size;
	} else {
		size = tsize;
	}
	hv_ptr = (tValue*)malloc(tsize*sizeof(tValue));

	dinit(tsize);

	return;
}

};
