#include<iostream>
using namespace std;

int main()
{
	int index;
	cout<<"this is a switch example"<<endl;
	cin>>index;

	switch(index)
	{
		case(1): cout<<"you have selected 1"<<endl;
	        break;
	       	case(2): cout<<"you have selected 2"<<endl;
	        break;
		case(3): cout<<"you have selected 3"<<endl;
	}
   return 0; 
}
