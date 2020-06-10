#include <string>
#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental;

int main() {

	std::string path = "/home/ashutosh/Desktop/CPP_Exercises/adv_opp";
	for (const auto & entry : fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;
}

