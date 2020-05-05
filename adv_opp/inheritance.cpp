#include "class_def.h"
#include <iostream>

int main(){
        
	class exp : public student
	{public:
exp(int grade, int age, std::string name): grade_(grade),age_(age),name_(name){}	};

	exp stpx(12,17,"Jennifer Lawerence");
	stpx.printer();

	/*studentp sstp(12,17,"Jennifer Lawerence");
	sstp.printer();
	int x = sstp.getage();
	std::cout<<x<<"\n";
	sstp.setage(18);
	int y = sstp.getage();
	std::cout<<"new age is "<<y<<"\n";
	studentp sstpr(11,16,"Jennifer Conelley");
        sstpr.printer();
        int z = sstpr.getage();
        std::cout<<x<<"\n";
        sstpr.setage(27);
        int k = sstpr.getage();
        std::cout<<"new age is "<<k<<"\n";
*/
	return 0;

}
