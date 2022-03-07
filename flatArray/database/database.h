#include"controller.h"

namespace FLATARRAY {

class FlatArray {
public:
	FlatArray(int size);

	tValue* getDevicePtr();
	tValue* getHostPtr();

	void init(int isize);
	void clean();

	tSize getSize();
	
	void dToH();
	void hTod();

	void printHost();

private:
    tValue* dv_ptr;
    tValue* hv_ptr;

	tSize size;
};

};
