/*Now I would like you to do a switch statement with breaks
**between the cases. Create a program that asks the user for
**two float numbers. Then asks the user if they would like to:
**add the numbers, subtract the numbers, multiply the numbers, 
**divide the numbers.
**The program should then print the numbers with the chosen
**operation and the solution. 
*/

#include <iostream>


int main()
{
    float in1, in2,out;
    char symb;
    
    std::cout<<"Enter two numbers:\n";
    std::cin>>in1;
    std::cin>>in2;
    std::cout<<"Enter the operation '+','-','*','/':\n";
    std::cin>>symb;
    
    switch(symb)
    {
        case('+'): {out = in1+in2; std::cout<<"you have selected + , and the results is: "<<out;break;}
        case('-'): {out = in1-in2; std::cout<<"you have selected - , and the results is: "<<out;break;}
        case('*'): {out = in1*in2; std::cout<<"you have selected * , and the results is: "<<out;break;}
        case('/'): {out = in1/in2; std::cout<<"you have selected / , and the results is: "<<out;break;}
    }
    return 0;
}
