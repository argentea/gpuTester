#include "database.h"
#include <fstream>

namespace FLATARRAY {

void FlatArray::printHost(std::ostream& out){
	for(int i = 0; i < size; i++){
		out << hv_ptr[i] << " ";
	}
	out << std::endl;
}


void FlatArray::printCompress(std::ostream& out){
	tValue tmp = 0;
	tSize count = 0;
	for(int i = 0; i < size; i++){
		if(tmp == hv_ptr[i]){
			count++;
			continue;
		}else {
			out << tmp << ": " << count << std::endl;
			tmp = hv_ptr[i];
			count = 1;
		}
	}
	out << tmp << ": " << count << std::endl;
}
};
