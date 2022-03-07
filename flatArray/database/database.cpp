#include"database.h"

namespace FLATARRAY {

FlatArray::FlatArray(int size): size(size) {
}

tValue* FlatArray::getDevicePtr() {
    return dv_ptr;
}

tValue* FlatArray::getHostPtr() {
    return hv_ptr;
}

};
