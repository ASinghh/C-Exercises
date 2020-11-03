
#include <string>
#include <iostream>

using namespace std;
using std::string;
using std::to_string;


int main(){

    string line = "Name = Ubuntu";
    line.replace(line.begin(), line.end(), ' ', '_');
    line.replace(line.begin(), line.end(), '=', ' ');
    line.replace(line.begin(), line.end(), '"', ' ');
    std::cout<<line;
    return 0;

}