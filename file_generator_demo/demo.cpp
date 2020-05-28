#include <iostream>
#include <string>
int main(){
        
	std::cout<<"Enter File Name: "<<"\n"<<std::endl;
	
	std::string filename;

	std::getline (std::cin,filename);

        std::cout<<"\n"<<"Q1: What is your companies diversity policy "<<"\n"<<std::endl;	

	std::cout<<"please enter the index of the category most applicable to the question"<<"\n"<<"1. Diversity"<<"\n"<<"2. Compliance"<<"\n"<<"3. Security"<<"\n"<<"4. Not sure"<<"\n"<<std::endl;

	int index;

	cin>>index;

	cout<<"\n"
	return 0;
}
