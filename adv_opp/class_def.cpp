#include "class_def.h"
#include <iostream>
#include <string>
#include <cmath>


student::student(int grade, int age, std::string name): grade_(grade), age_(age), name_(name){};
void student::printer(){std::cout<<"The student by the name of "<<name_<<", and of "<<age_<<" years of age, is in grade "<<grade_<<"\n";
}

studentp::studentp(int grade, int age, std::string name): grade_(grade), age_(age), name_(name){};

void studentp::printer(){std::cout<<"The student by the name of "<<name_<<", and of "<<age_<<" years of age, is in grade "<<grade_<<"\n";
}
int studentp::getage(){return age_;}

/*class studentpv{


  public:
  studentpv(int grade, int age, std::string name);
  int grade_;
  int age_;
  std::string name_;
  void printer(){std::cout<<"The student by the name of "<<name_<<", and of "<<age_<<" years of age, is in grade "<<grade_<<"\n";
  }
  protected:



  private:


};

studentpv::studentpv(int grade, int age, std::string): grade_(grade), age_(age), name_(name){};
*/

