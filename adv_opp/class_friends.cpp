#include <iostream>



class Square{
      public:
      Square(float side_):side(side_){};
      friend class Rectangle;


      private:
      float side;
};

class Rectangle{
        public:
        Rectangle(Square sq){
                width = sq.side;
                height = 2*sq.side;
        };

        float area(){ return width*height;}
        private:
        float width;
        float height;

};


int main(){
	Square sqq(1.414);
	Rectangle rec(sqq);
	std::cout<<rec.area()<<std::endl;
	return 0;

}
