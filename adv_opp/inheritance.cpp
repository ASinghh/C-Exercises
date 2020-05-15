#include "class_def.h"
#include <iostream>

using namespace std;


class exprt : public student{
public:
exprt(int grade, int age, std::string name) : student( grade, age,  name){};
} ;

class exprot : public studentpr{
public:
exprot(int grade, int age, std::string name) : studentpr( grade, age,  name){};
void ageprinter() {
    int age;
    age = getage();
    cout<<age;

}

} ;


int main(){
        
   
	exprt stpx(12,15,"Chadwick Boseman"); 
        stpx.printer();
	std::cout<<stpx.name_<<std::endl;
        exprot stprx(12,15,"Chadwick Boseman");
        stprx.printer();
        stprx.ageprinter();


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
