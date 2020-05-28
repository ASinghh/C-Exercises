#include <iostream>
#include <string>
int main(){

	std::cout<<"Hi! I am your friendly RFP bot and we will together make the response doccument."<<"\n"<<std::endl;
        
	std::cout<<"Please enter the name of the file with the question: "<<"\n"<<std::endl;
	
	std::string filename;

	std::getline (std::cin,filename);

	std::cout<<"\n"<<"Great!"<<std::endl;

        std::cout<<"\n"<<"Q1: What is your company's diversity policy? "<<"\n"<<std::endl;	

	std::cout<<"Please enter the category most applicable to the question,"<<"\n"<<"1. Diversity"<<"\n"<<"2. Compliance"<<"\n"<<"3. Security"<<"\n"<<"4. Not sure"<<"\n"<<std::endl;

	int index;

        std::cin>>index;

	std::cout<<"\n"<<"Nice! Now please Select a recommendtion that is similar to the pertinent question,"<<"\n"<<"1. Explain Dell's Diversity policy."<<"\n"<<"2. How Diverse is Dell?"<<"\n"<<"3. What kind of food diversity do you enjoy at Dell's Cafeteria?"<<"\n"<<"4. None of the above."<<"\n"<<std::endl;

	int quest;

	std::cin>>quest;

	std::cin.ignore();

	std::string manu;

	if(quest == 4){
		std::cout<<"\n"<<"Sorry to hear that, Please use the space below to enter the answer  manually."<<"\n"<<" Don't worry, I learn continuously, next time I will suggest your entered answer!"<<"\n"<<std::endl;
	

		std::getline (std::cin,manu);

		std::cout<<"\n"<<"Great, now moving on,"<<"\n\n"<<"Q2. How Secure is RxRail 200?"<<"\n\n"<<"please enter the index of the category most applicable to the question:"<<"\n"<<"1. Security"<<"\n"<<"2. Sales"<<"\n"<<"3. Compliance"<<"\n"<<"4. Not sure"<<"\n"<<std::endl;

                int index2;
 
                std::cin>>index2;
	}

	else{
		                std::cout<<"\n"<<"Great, now moving on,"<<"\n\n"<<"Q2. How Secure is RxRail 200"<<"\n\n"<<"please enter the index of the category most applicable to the question:"<<"\n"<<"1. Security"<<"\n"<<"2. Sales"<<"\n"<<"3. Compliance"<<"\n"<<"4. Not sure"<<"\n"<<std::endl;

                int index2;

                std::cin>>index2;
        }



		
	return 0;
}
