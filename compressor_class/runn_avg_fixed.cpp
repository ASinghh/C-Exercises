#include "runn_avg_fixed.h"
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <iostream>



Runing_Avg_Fixed::Runing_Avg_Fixed(std::vector<double> ini_vec, double win_sz){

	local_summary_vec = std::vector<double>(ini_vec.begin(), ini_vec.end()-1);
	std::vector<double> test = std::vector<double>(ini_vec.begin(), ini_vec.end()-2);
        int k = test.size();
	int j = local_summary_vec.size();
	std::cout<<test[0]<<test[1]<<test[2]<<test[3];
	window_size = win_sz;
	current_time_step = ini_vec.back();
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
                last_saved_time = current_time_step;
		current_time_step = vec.back();
		write_local_summ();
		local_summary_vec = std::vector<double>(vec.begin(), vec.end()-1);
        }

        else{
		update_local_summ(vec);
	
	}
}

void Runing_Avg_Fixed::write_local_summ(){
}

void Runing_Avg_Fixed::update_local_summ(const std::vector<double>& vec){

	double mul_saved = current_time_step + 1.0;// is the time vec starting from 0 or 1?
        double mul_input = 1.0;
        double modif = vec.back() + 1.0;
	
	std::vector<double> input_vector = std::vector<double>(vec.begin(), vec.end()-1);        std::vector<double> saved_vector = local_summary_vec;

	std::transform(saved_vector.begin(),saved_vector.end(), saved_vector.begin(), [mul_saved](double &c){return c*mul_saved;});
        std::transform(input_vector.begin(),input_vector.end(), input_vector.begin(), [mul_input](double &c){return c*mul_input;});
        assert(saved_vector.size() == input_vector.size());

	std::vector<double> local_summary_vec;
        std::transform(saved_vector.begin(), saved_vector.end(), input_vector.begin(),
                   std::back_inserter(local_summary_vec), std::plus<double>());
        std::transform(local_summary_vec.begin(),local_summary_vec.end(), local_summary_vec.begin(), [modif](double &c){return c/modif;});

	current_time_step = modif;

}




int main(){

        std::vector<double> vec1 =  {1,2,3,4,0};
	Runing_Avg_Fixed RAF(vec1,3.0);
        std::cout<<RAF.last_saved_time<<" " <<RAF.window_size<<" " <<RAF.current_time_step<<" "<<RAF.local_summary_vec[4]<<"\n";
	std::vector<double> vec2 =  {2,2,2,2,1};
        RAF.fixed_blocking(vec2);
	std::cout<<RAF.local_summary_vec[0]<<RAF.local_summary_vec[1]<<RAF.local_summary_vec[2]<<RAF.local_summary_vec[3]<<RAF.local_summary_vec[4]<<"\n";
	return 0;
}
