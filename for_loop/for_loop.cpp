/*Write a program that asks a user for five numbers.
**Print out the sum and average of the five numbers.
*/

#include<iostream>
#include<sstream>
using namespace std;

int main()

{
      cout<<"Please enter the 5 numbers you want averaged after the prompt"<<endl;
      float sum = 0;
      float holder = 0;
      for(int i =0 ; i<5; i++)
      {cout<<"please enter the "<<i<<"th number: "; 
       cin>>holder;
       cout<<"\n";
       sum = sum + holder;
      }
      cout<<"the sum of the provided 5 numbers is: "<<sum<<"\n";
      sum = sum/5;
      cout<<"the average of the provided 5 numbers is: "<<sum;
       
    
    return 0;
}

