#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include "parser_consts.h"
#include "parser_helper.h"
#include "process.h"
#include "linux_parser.h"
#include "format.h"


using std::string;
using std::to_string;
using std::vector;



Process::Process(int pid) : processId_(pid) {
  // initialize all val
 vector<string> cpuNumbers = ReadFile(pid);

  utime_ = stof(cpuNumbers[13]);
  stime_ = stof(cpuNumbers[14]);
  cutime_ = stof(cpuNumbers[15]);
  cstime_ = stof(cpuNumbers[16]);
  starttime_ = stof(cpuNumbers[21]);
}




// TODO: Return this process's ID
int Process::Pid() { return 0; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { return 0; }

// TODO: Return the command that generated this process
string Process::Command() { return string(); }

// TODO: Return this process's memory utilization
string Process::Ram() { return string(); }

// TODO: Return the user (name) that generated this process
string Process::User() { return string(); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return 0; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a[[maybe_unused]]) const { return true; }
