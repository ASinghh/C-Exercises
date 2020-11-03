#include <string>
#include <iostream>
#include <algorithm> 

using namespace std;





int main(){

    string line = "Name = Ubuntu";
    std::replace(line.begin(), line.end(), ' ', '_');
    std::replace(line.begin(), line.end(), '=', ' ');
    std::replace(line.begin(), line.end(), '"', ' ');
    std::cout<<line;
    return 0;

}