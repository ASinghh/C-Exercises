#include <iostream>

class A {
	public:
	int x;
};

class B{
    public:
    int y;
};


class C :public A, public B {
       public:
       int suma (){
	       return x+y;
       }
};

int main(){
	C tester;
	tester.x = 5;
	tester.y = 6;
	std::cout<<tester.suma()<<std::endl;


return 0;
}
