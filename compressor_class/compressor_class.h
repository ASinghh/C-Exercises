#include <vector>
#include <fstream>
#include <string>



#ifndef COMPRESSOR_CLASS_H
#define COMPRESSOR_CLASS_H

class compressor

{
	public:
		compressor(std::string name);                
		std::vector<double> local_value_store();     
		std::vector<float> cal_runn_avg(std::vector<float>, std::vector<float>);
		void write_runn_avg(std::vector<float>);
             


	private:
		std::string name;

};
#endif
