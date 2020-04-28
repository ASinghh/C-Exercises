#include "class_def.h"
#include <iostream>

int main(){
        student stud(10,15,"Chadwick Boseman");
        stud.printer();
	studentp sstp(12,17,"Jennifer Lawerence");
	sstp.printer();
	int x = sstp.getage();
	std::cout<<x;
	return 0;

}
