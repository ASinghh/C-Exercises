#include "running_average.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>


Runing_Avg::Runing_Avg(std::string flname): filename(flname){};

std::vector<float> Runing_Avg::read_runn_avg(){
	
       	const std::string flname = filename;
         std::ifstream fs;
         fs.open(flname.c_str(), std::fstream::in);
         if(!fs.is_open())
         {
            std::cout << "Could not open file" << std::endl;
            return {1.1,2.2};
         }
         std::string lastline;
         lastline  =  getLastLineInFile(fs);
         std::string buf;                 // Have a buffer string
         std::stringstream ss(lastline);       // Insert the string into a stream
         std::vector<float> tokens; // Create vector to hold our value
         while (ss >> buf)
            tokens.push_back(std::stof(buf));
         return tokens;
  }


std::vector<float>  Runing_Avg::cal_runn_avg(std::vector<float> saved_vector, std::vector<float> input_vector){
	
	float mul_saved = saved_vector.back();
        float mul_input = input_vector.back();
        float modif = mul_saved + mul_input;
        std::transform(saved_vector.begin(),saved_vector.end(), saved_vector.begin(), [mul_saved](float &c){return c/mul_saved;});
        std::transform(input_vector.begin(),input_vector.end(), input_vector.begin(), [mul_input](float &c){return c/mul_input;});
        assert(saved_vector.size() == input_vector.size());
        std::vector<float> result;
        std::transform(saved_vector.begin(), saved_vector.end(), input_vector.begin(),
                   std::back_inserter(result), std::plus<float>());
        std::transform(result.begin(),result.end(), result.begin(), [modif](float &c){return c/modif;});
        result.back() = modif;
        return result;
}


void Runing_Avg::write_runn_avg(std::vector<float> result){
	        
	std::ofstream fout(filename, std::ios_base::app);
        fout << std::setprecision(10);
        for(auto const& x : result)
            fout << x << ' ';
        fout <<'\n';
        fout.close();

}

std::string Runing_Avg::getLastLineInFile(std::ifstream& in){
    std::string line;
    while (in >> std::ws && std::getline(in, line)) // skip empty lines
        ;

    return line;

}




int main()
{
    const std::string flname = "vec_log.txt";
    Runing_Avg RA(flname);
    std::vector<float> v1 = RA.read_runn_avg();
    std::vector<float> v2;
    std::cout << "Type in a list of 5 numbers " <<std::endl;

        float input = 0;

        for (int i = 0; i < 5; i++)
        {
                std::cin >> input;
                v2.push_back(input);

        }

    std::vector<float> v3 = RA.cal_runn_avg(v1, v2);
    std::cout << "vector elements are: ";
     for (int i = 0; i < v3.size(); ++i){
             std::cout << v3[i] << ' ';
    }
   RA.write_runn_avg(v3);



	return 0;
}



