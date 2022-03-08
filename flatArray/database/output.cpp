#include "database.h"
#include <fstream>

namespace FLATARRAY {

void FlatArray::printHost(std::ofstream out){
	for(int i = 0; i < size; i++){
		out << hv_ptr[i] << " ";
	}
	out << std::endl;
}

};
