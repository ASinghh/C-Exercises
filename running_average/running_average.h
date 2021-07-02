#include <vector>
#include <fstream>
#include <string>



#ifndef RUNNING_AVERAGE_H
#define RUNNING_AVERAGE_H

class Runing_Avg

{
	public:
		Runing_Avg(std::string flname);
		std::vector<float> read_runn_avg();
		std::vector<float> cal_runn_avg(std::vector<float>, std::vector<float>);
		void write_runn_avg(std::vector<float>);
             


	private:
		std::string filename;
//		bool moveToStartOfLine(std::ifstream&);
		std::string getLastLineInFile(std::ifstream& in);

};

#endif


