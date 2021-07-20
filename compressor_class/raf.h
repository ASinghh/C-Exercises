#include <vector>
#include <string>



#ifndef RAF_H
#define RAF_H

class Runing_Avg_Fixed

{
        public:
                Runing_Avg_Fixed(std::vector<double>, double);
                std::vector<double> local_summary_vec;
                void fixed_blocking(const std::vector<double>&);


        private:
                double last_saved_time;
                double window_size;
		void update_local_summ(const std::vector<double>&);
                void write_local_summ();

};

#endif

