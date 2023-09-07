/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

int main() {
    srand(time(0));   // Initialization for random function

    std::vector<std::string> surnames { "Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis" };
    
    std::vector<std::string> lines;
    std::string line;
    std::string filename = "/Users/bertin/CLionProjects/COEN243/FinalProject/student.txt";
    std::ifstream file(filename);

    while (std::getline(file, line))
    {
        size_t found = line.find("fname");
        if(found != std::string::npos)
        {
            line.replace(found, 9, surnames[rand() % surnames.size()]);
        }

        lines.push_back(line);
    }

    file.close();

    // Write the modified data back into the file
    std::ofstream outfile(filename);
    for(auto &line: lines)
        outfile << line << std::endl;

    outfile.close();
    
    return 0;
}
 */

#include <iostream>
#include "Employee.h"
using namespace std;

int main(){
    Student s1("bertin", "mihigo sano", 40157663, "2000/09/02", 3.5, 2022, 42, 'B');
}