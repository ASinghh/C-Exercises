#include "rav.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>


Runing_Avg_Var::Runing_Avg_Var(std::vector<double> ini_vec, double thres){

        local_summary_vec = ini_vec;
	threshold = thres;
}


double Runing_Avg_Var::getMold(const std::vector<double>& vec){

        int n = vec.size();
        double sum = 0.0;
        for (int i = 0; i<n-1; ++i)
            sum += vec[i] * vec[i];
        return sqrt(sum);
}


double Runing_Avg_Var::getSimilarity(const std::vector<double>& lhs, const  std::vector<double>& rhs){

        int n = lhs.size();
        double tmp = 0.0;  //Inner product
        for (int i = 0; i<n-1; ++i)
            tmp += lhs[i] * rhs[i];
        return tmp / (getMold(lhs)*getMold(rhs));

}


void Runing_Avg_Var::var_blocking(const std::vector<double>& vec){

       double cosine_sim = getSimilarity(vec,local_summary_vec);
	if(cosine_sim < 1-threshold){
                write_local_summ();
                local_summary_vec = vec;
        }

        else{update_local_summ(vec);}
}


void Runing_Avg_Var::write_local_summ(){

	std::cout<<"the vector is being written"<<"\n";
}


void Runing_Avg_Var::update_local_summ(const std::vector<double>& vec){

        double mul_saved = local_summary_vec.back() + 1.0;
        double mul_input = 1.0;
        double modif = vec.back() + 1.0;
        std::vector<double> input_vector = vec;

        std::transform(local_summary_vec.begin(),local_summary_vec.end(), local_summary_vec.begin(), [mul_saved](double &c){return c*mul_saved;});
        std::transform(input_vector.begin(),input_vector.end(), input_vector.begin(), [mul_input](double &c){return c*mul_input;});

        std::vector<double> result;
        std::transform(local_summary_vec.begin(), local_summary_vec.end(), input_vector.begin(),std::back_inserter(result), std::plus<double>());
        std::transform(result.begin(),result.end(), result.begin(), [modif](double &e){return e/modif;});

        result.back() = vec.back();
        local_summary_vec = result;
}

int main(){

        std::vector<double> vec1 =  {1,2,3,4,0};
        Runing_Avg_Var RAV(vec1,0.5);
        std::cout<<RAV.local_summary_vec[4]<<"\n";
        std::vector<double> vec2 =  {2,2,2,2,1};
        RAV.var_blocking(vec2);
        std::cout<<RAV.local_summary_vec[0]<<RAV.local_summary_vec[1]<<RAV.local_summary_vec[2]<<RAV.local_summary_vec[3]<<RAV.local_summary_vec[4]<<"\n";

        std::vector<double> vec3 = {1,1,1,2,2};
        RAV.var_blocking(vec3);
        std::cout<<RAV.local_summary_vec[0]<<" "<<RAV.local_summary_vec[1]<<" "<<RAV.local_summary_vec[2]<<" " <<RAV.local_summary_vec[3]<<" " <<RAV.local_summary_vec[4]<<"\n";
        std::cout<<" " <<"\n";
        std::vector<double> vec4 = {1,1,1,2,3};
        RAV.var_blocking(vec4);
        std::cout<<RAV.local_summary_vec[0]<<" "<<RAV.local_summary_vec[1]<<" "<<RAV.local_summary_vec[2]<<" " <<RAV.local_summary_vec[3]<<" " <<RAV.local_summary_vec[4]<<"\n";
        std::cout<<" " <<"\n";


        return 0;
}



