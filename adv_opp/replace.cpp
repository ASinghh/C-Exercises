#include <string>
using namespace std;

void main(){

    string line = "Name = Ubuntu";
    std::replace(line.begin(), line.end(), ' ', '_');
    std::replace(line.begin(), line.end(), '=', ' ');
    std::replace(line.begin(), line.end(), '"', ' ');
    cout<<line;

}