#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "passport.cpp"

using namespace std;

std::vector<std::string> readData(std::ifstream& inputFile)
{
    std::string line;
    std::vector<std::string> passportData;
    while (std::getline(inputFile, line))
        passportData.push_back(line);

    return passportData;
}

Passport parsePassport(std::string data)
{
    std::cout << data << std::endl;
    Passport passport;
    std::istringstream iss(data);
    std::string token;

    while (iss >> token) {
        std::string key = token.substr(1, 4);
        std::string value = token.substr(5);

        if (key == "hcl") passport.setHcl(value);
        else if (key == "ecl") passport.setEcl(value);
        else if (key == "eyr") passport.setEyr(value);
        else if (key == "pid") passport.setPid(value);
        else if (key == "iyr") passport.setIyr(value);
        else if (key == "hgt") passport.setHgt(value);
        else if (key == "byr") passport.setByr(value);
        else if (key == "cid") passport.setCid(value);
    }

    return passport;
}

int main()
{
    std::string path = "/mnt/extraExt4/Projects/nicehash-test/Test2/data/Test2.txt";
    std::ifstream inputFile(path);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::vector<std::string> passportVector = readData(inputFile);
    inputFile.close();

    // build the passport vector
    std::vector<Passport> passports;
    std::string passportData;

    for (auto line : passportVector)
    {
        if (line == "\r")
        {
            passports.push_back(parsePassport(passportData));
            passportData.clear();
        }
        else
        {
            passportData += " " + line;
        }
    }

    // Process the last passport entry in case the file doesn't end with an empty line
    if (!passportData.empty()) {
        std::cout << "Doesn't end with an empty line" << std::endl;
        passports.push_back(parsePassport(passportData));
    }

    for (auto passport : passports)
        cout << passport.toString() << endl;
    std::cout << "number of passports: " << passports.size() << std::endl;

    return 0;
}