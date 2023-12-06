#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Operation
{
    NOP,
    ACC,
    JMP
};

struct Instruction
{
    string operation;
    int argument;
};

struct Env
{
    int index = 0;
    int accumulator = 0;
    vector<Instruction> instructions;
};

Env getEnv(ifstream& inputFile)
{
    Env env = Env();
    std::string line;
    std::vector<std::string> passportData;
    while (getline(inputFile, line))
    {
        Instruction i = Instruction();
        i.operation = line.substr(0, 3);
        i.argument = stoi(line.substr(4));
    }
    return env;
}

int main()
{
    std::string path = "/mnt/extraExt4/Projects/nicehash-test/Test1/data/Test1.txt";
    std::ifstream inputFile(path);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    Env env = getEnv(inputFile);
}