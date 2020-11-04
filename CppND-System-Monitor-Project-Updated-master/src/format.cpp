#include <string>

#include "format.h"

using std::string;

using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
	int hh, remaining_s, mm, ss;

	remaining_s = seconds % 86400;
	// Get hours
	hh = remaining_s / 3600;
	remaining_s = remaining_s % 3600;
	// Get minutes
	mm = remaining_s / 60;
	// Get total remaining seconds
	ss = remaining_s % 60;

	return to_string(hh) + ":" + to_string(mm) + ":" + to_string(ss);

	
}