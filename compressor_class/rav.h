#include <vector>
#include <string>



#ifndef RAV_H
#define RAV_H

class Runing_Avg_Var

{
        public:
                Runing_Avg_Var(std::vector<double>, double);
                void update_local_summ(const std::vector<double>&);
                void write_local_summ();
                std::vector<double> local_summary_vec;
                void var_blocking(const std::vector<double>&);


        private:
                double getMold(const std::vector<double>&);
                double getSimilarity(const std::vector<double>&,const std::vector<double>&);
		double threshold;

};

#endif

