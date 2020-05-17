#include <string>
#define pi 3.14159


#ifndef CLASS_DEF_H
#define CLASS_DEF_H

class student{


  public:
  student(int grade, int age, std::string name);
  int grade_;
  int age_;
  std::string name_;
  void printer();

};

class studentp{


  public:
  studentp(int grade, int age, std::string name);
  void printer();
  int getage();
  void setage(int);
  private:
  int grade_;
  int age_;
  std::string name_;

};

class studentpr{


  public:
  studentpr(int grade, int age, std::string name);
  void printer();
  protected:
  int getage();
  void setage(int);
  private:
  int grade_;
  int age_;
  std::string name_;

};


class LineSegment{
	public:
	LineSegment(float length_);
	void PrintLen();
	float GetLen();
	private:
	float length;

};



class Circle{
	public:
	Circle(LineSegment radius);
	float GetArea();
	float GetCircum();

	private:
	LineSegment radius_;
};


#endif
