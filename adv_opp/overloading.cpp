#include <iostream>
#include <ctime>

class Complex{
      private:
      int real, imag;
      public:
      Complex(int i= 0 , int j= 0 ): real(i), imag(j){};
      Complex operator + (Complex const &obj){
	      Complex a2;
	      a2.real = real + obj.real;
	      a2.imag = imag + obj.imag;
	      return a2;
      }

      void printcomp(){std::cout<<"real part of the number is "<<real<<", imaginary part of the number is "<<imag<<std::endl;}
};

class Complex2{
      private:
      int real, imag;
      public:
      Complex2(int i , int j ): real(i), imag(j){}
      Complex2(int i):real(i){imag = 666;}
      void printcomp2(){std::cout<<"real is "<<real<<", image is "<<imag<<std::endl;}

};




int main(){
	Complex c1(2,3),c2(4,6);
       	Complex c3 = c1+c2;
	c3.printcomp();
	Complex2 c4 = (9,9);
	c4.printcomp2();
	Complex2 c5 = (9);
	c5.printcomp2();

	return 0;
}
