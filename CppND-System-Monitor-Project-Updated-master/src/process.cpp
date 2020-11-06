#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include "process.h"
#include "linux_parser.h"
#include "format.h"


using std::string;
using std::to_string;
using std::vector;



Process::Process(int pid){
  // initialize all val
  processId_= pid;
 //std::vector<string> cpuNumbers = ReadFile(pid);

  //utime_ = stof(cpuNumbers[13]);
  //stime_ = stof(cpuNumbers[14]);
  //cutime_ = stof(cpuNumbers[15]);
 // cstime_ = stof(cpuNumbers[16]);
  //starttime_ = stof(cpuNumbers[21]);
};




// TODO: Return this process's ID
int Process::Pid() { return processId_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
  long jiffies_start, jiffies_end;
	long uptime_start, uptime_end, delta;

	jiffies_start = LinuxParser::ActiveJiffies(processId_);
  	uptime_start = LinuxParser::UpTime(processId_);
  	// Wait 100ms
	usleep(100000); // in microseconds

	jiffies_end = LinuxParser::ActiveJiffies(processId_);
	uptime_end = LinuxParser::UpTime(processId_);

	delta = uptime_end - uptime_start;
	// if delta is 0, it means the process doesn't use
	// the CPU anymore
	if (delta == 0){
 		return 0;
	}

	return (float)(jiffies_end - jiffies_start) / (float)(uptime_end - uptime_start);

  
 }

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(processId_); }

// TODO: Return this process's memory utilization
string Process::Ram() { return  LinuxParser::Ram(processId_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(processId_); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(processId_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
	long ram = stol(LinuxParser::Ram(processId_));
	long ram_a = stol(LinuxParser::Ram(a.processId_));

	if (ram > ram_a) {
		return true;
	}

	return false;
}
