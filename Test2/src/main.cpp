#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> readdata(std::ifstream& inputFile)
{
    std::string line;
    std::vector<std::string> passportData;
    while (std::getline(inputFile, line))
        passportData.push_back(line);

    return passportData;
}

int main()
{
    std::string path = "../data/Test2.txt";
    std::ifstream inputFile(path);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::vector<std::string> passportData = readdata(inputFile);
    inputFile.close();

    

    return 0;
}