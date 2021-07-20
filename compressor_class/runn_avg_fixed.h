#include <vector>
#include <string>



#ifndef RUNN_AVG_FIXED_H
#define RUNN_AVG_FIXED_H

class Runing_Avg_Fixed

{
	public:
		Runing_Avg_Fixed(std::vector<double>, double);
		void update_local_summ(const std::vector<double>&);
		void write_local_summ();
             


	//private:
		double last_saved_time;
		double window_size;
		double current_time_step;
		std::vector<double> local_summary_vec;
		double getMold(const std::vector<double>&);
		double getSimilarity(const std::vector<double>&,const std::vector<double>&);
		void fixed_blocking(const std::vector<double>&);

};

#endif
