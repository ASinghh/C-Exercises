#include "runn_avg_fixed.h"
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <iostream>



Runing_Avg_Fixed::Runing_Avg_Fixed(std::vector<double> ini_vec, double win_sz){

	local_summary_vec = ini_vec;
	//std::vector<double> test = std::vector<double>(ini_vec.begin(), ini_vec.end()-2);
        //int k = test.size();
	//int j = local_summary_vec.size();
	//std::cout<<test[0]<<test[1]<<test[2]<<test[3];
	window_size = win_sz;
//	current_time_step = ini_vec.back();
        last_saved_time = ini_vec.back() - 1.0; //check logic
}

double Runing_Avg_Fixed::getMold(const std::vector<double>& vec){

        int n = vec.size();
        double sum = 0.0;
        for (int i = 0; i<n; ++i)
            sum += vec[i] * vec[i];
        return sqrt(sum);
}


double Runing_Avg_Fixed::getSimilarity(const std::vector<double>& lhs, const  std::vector<double>& rhs){
        int n = lhs.size();
        assert(n == rhs.size());
        double tmp = 0.0;  //Inner product
        for (int i = 0; i<n; ++i)
            tmp += lhs[i] * rhs[i];
        return tmp / (getMold(lhs)*getMold(rhs));

}

void Runing_Avg_Fixed::fixed_blocking(const std::vector<double>& vec){

       if(vec.back()-last_saved_time > window_size){
                last_saved_time = local_summary_vec.back();
		//current_time_step = vec.back();
		write_local_summ();
		local_summary_vec = vec;
        }

        else{
		update_local_summ(vec);
	
	}
}

void Runing_Avg_Fixed::write_local_summ(){
}

void Runing_Avg_Fixed::update_local_summ(const std::vector<double>& vec){

	double mul_saved = local_summary_vec.back() + 1.0;// is the time vec starting from 0 or 1?
        double mul_input = 1.0;
        double modif = vec.back() + 1.0;
	
	std::vector<double> input_vector = vec;
//	std::vector<double> saved_vector = local_summary_vec;

	std::transform(local_summary_vec.begin(),local_summary_vec.end(), local_summary_vec.begin(), [mul_saved](double &c){return c*mul_saved;});
        std::transform(input_vector.begin(),input_vector.end(), input_vector.begin(), [mul_input](double &c){return c*mul_input;});
        assert(local_summary_vec.size() == input_vector.size());

	std::vector<double> result;
	std::transform(local_summary_vec.begin(), local_summary_vec.end(), input_vector.begin(),std::back_inserter(result), std::plus<double>());
        std::transform(result.begin(),result.end(), result.begin(), [modif](double &e){return e/modif;});
        result.back() = vec.back();
	local_summary_vec = result;


}




int main(){

        std::vector<double> vec1 =  {1,2,3,4,0};
	Runing_Avg_Fixed RAF(vec1,3.0);
        std::cout<<RAF.last_saved_time<<" " <<RAF.window_size<<" "<<RAF.local_summary_vec[4]<<"\n";
	std::vector<double> vec2 =  {2,2,2,2,1};
        RAF.fixed_blocking(vec2);
	std::cout<<RAF.local_summary_vec[0]<<RAF.local_summary_vec[1]<<RAF.local_summary_vec[2]<<RAF.local_summary_vec[3]<<RAF.local_summary_vec[4]<<"\n";

	std::vector<double> vec3 = {1,1,1,2,2};
        RAF.fixed_blocking(vec3);
        std::cout<<RAF.local_summary_vec[0]<<" "<<RAF.local_summary_vec[1]<<" "<<RAF.local_summary_vec[2]<<" " <<RAF.local_summary_vec[3]<<" " <<RAF.local_summary_vec[4]<<"\n";
        std::cout<<RAF.last_saved_time<<" " <<RAF.window_size<<" " <<"\n";
        std::vector<double> vec4 = {1,1,1,2,3};
        RAF.fixed_blocking(vec4);
        std::cout<<RAF.local_summary_vec[0]<<" "<<RAF.local_summary_vec[1]<<" "<<RAF.local_summary_vec[2]<<" " <<RAF.local_summary_vec[3]<<" " <<RAF.local_summary_vec[4]<<"\n";
        std::cout<<RAF.last_saved_time<<" " <<RAF.window_size<<" "<<"\n";


	return 0;
}
