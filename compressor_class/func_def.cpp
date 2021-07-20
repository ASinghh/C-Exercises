#include <iostream>
#include <sstream>
#include <vector>
#include<fstream>
#include <cmath>
#include <cassert>


void write_value(std::vector<double> result, std::string filename){
	        
	std::ofstream fout(filename);
	//fout << std::setprecision(10);

	for(auto const& x : result)
    		fout << x << ' ';
	fout <<'\n';

}
	

	
	
void fixed_blocking(std::vector<double> vec, double last_saved_time, double window_size){
	std::string filename = "save.txt";
	//std::vector<double> v3 = std::vector<double>(vec.begin(), vec.end()-1);

	if(vec.back()-last_saved_time > window_size){
		double j = 69.00;
	        vec.push_back(69.00);
		std::cout<<"last element is "<< vec[5];
		write_value(vec, filename);
	}

	else{}
}


double getMold(std::vector<double> vec){   //Find the modulus length of the vector
        int n = vec.size();
        double sum = 0.0;
        for (int i = 0; i<n; ++i)
            sum += vec[i] * vec[i];
	std::cout<<sum;
        return sqrt(sum);
    }

double getSimilarity(std::vector<double>& lhs,  std::vector<double>& rhs){
        int n = lhs.size();
        assert(n == rhs.size());
        double tmp = 0.0;  //Inner product
        for (int i = 0; i<n; ++i)
	    //std::cout<<lhs.at(i)<<" "<<rhs.at(i);
            tmp += lhs[i] * rhs[i];
	std::cout<<tmp;
        return tmp / (getMold(lhs)*getMold(rhs));
    }
//void variable_blocking(std::vector<double> vec1, std::vector<double> vec2, double threshold){
  //      std::string filename = "save.txt";
    //    if(vec.back()-last_saved_time > window_size){
      //          write_value(vec, filename);
        //}

        //else{}
//}



int main(){  
    std::vector<double> v2;
    std::cout << "Type in a list of 5 numbers " <<std::endl;

        double input = 0;

        for (int i = 0; i < 5; i++)
        {
                std::cin >> input;
                v2.push_back(input);

        }
    
	double window;
	double last_saved;

//	std::vector<double> v3;
    //std::cout << "Type in a list of another 5 numbers " <<std::endl;

        //double input2 = 0;

       // for (int i = 0; i < 5; i++)
       // {
           //     std::cin >> input2;
         //       v3.push_back(input2);

       // }

 //       double window;
   //     double last_saved;
//	double cosinesim;
//	cosinesim = getSimilarity(v2,v3);
//	std::cout<<"cosine sim is "<< cosinesim;

	std::cout << "Type in the window size " <<std::endl;
	std::cin >> window;

	std::cout << "Type in the last saved time stamp " <<std::endl;
	std::cin >> last_saved;

	std::vector<double> v3 = std::vector<double>(v2.begin(), v2.end()-1);

	fixed_blocking(v2, last_saved, window);


	return 0;
}
