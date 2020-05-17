#include "class_def.h"
#include <iostream>
#include <cmath>
#include <iostream>



LineSegment::LineSegment(float length_):length(length_){};

void LineSegment::PrintLen() {
	std::cout<<length<<std::endl;
}

float LineSegment::GetLen() {
	return length;
}

Circle::Circle(LineSegment radius):radius_(radius){};

float Circle::GetArea(){
	float area;
	area = pi*radius_.GetLen()*radius_.GetLen();
	return area;
}

float Circle::GetCircum(){
	float circum;
	circum = 2*pi*radius_.GetLen();
	return circum;
}



int main() {

    LineSegment line(1.1);
    Circle circa(line);
    std::cout<<"area of the circle is "<<circa.GetArea()<<"circumference is "<<circa.GetCircum()<<std::endl;

    return 0;
}



