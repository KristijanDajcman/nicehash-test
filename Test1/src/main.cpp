#include <iostream>
#include <fstream>
#include <string>
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
    Operation operation;
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
        if (line.substr(0, 3) == "nop")
            i.operation = Operation::NOP;
        else if (line.substr(0, 3) == "acc")
            i.operation = Operation::ACC;
        else if (line.substr(0, 3) == "jmp")
            i.operation = Operation::JMP;

        i.argument = stoi(line.substr(4));
        env.instructions.push_back(i);
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

    while (env.index < env.instructions.size())
    {
        Instruction instruction = env.instructions[env.index];
        switch (instruction.operation)
        {
        case Operation::NOP:
            env.index++;
            break;
        case Operation::ACC:
            env.accumulator += instruction.argument;
            env.index++;
            break;
        case Operation::JMP:
            env.index = instruction.argument;
            break;
        default:
            break;
        }
    }

    cout << "Accumulator end value: " << env.accumulator << endl;
}