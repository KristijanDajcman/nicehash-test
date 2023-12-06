#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "passport.cpp"
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex myMutex;

vector<string> readData(ifstream& inputFile)
{
    string line;
    vector<string> passportData;
    while (getline(inputFile, line))
        passportData.push_back(line);

    return passportData;
}

bool validate(string data)
{
    istringstream iss(data);
    string token;

    int n_valid = 0;

    while (iss >> token) {
        string key = token.substr(0, 3);
        string value = token.substr(4);

        if (key == "hcl") n_valid++;
        else if (key == "ecl") n_valid++;
        else if (key == "eyr") n_valid++;
        else if (key == "pid") n_valid++;
        else if (key == "iyr") n_valid++;
        else if (key == "hgt") n_valid++;
        else if (key == "byr") n_valid++;
    }
    if (n_valid >= 7)
        return true;
    else
        return false;
}

void validCount(vector<string>& passports, size_t& valid, size_t start, size_t end)
{
    for (int i = start; i < end; i++)
    {
        if (validate(passports[i]))
        {
            myMutex.lock();
            valid++;
            myMutex.unlock();
        }
    }
}

int main(int argc, char* argv[])
{
    int numThreads = 1;
    string path = "Test2.txt";

    // Check if there are command line arguments
    if (argc > 1) {
        // Parse command line arguments
        numThreads = stoi(argv[1]);

        if (argc > 2) {
            path = argv[2];
        }
    }

    // Read data
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    vector<string> passportRaw = readData(inputFile);
    vector<string> passportStrings;
    inputFile.close();
 
    string passportData;

    for (string line : passportRaw)
    {
        if (line == "\r")
        {
            passportStrings.push_back(passportData);
            passportData.clear();
        }
        else
        {
            passportData += " " + line;
        }
    }

    int partSize = passportStrings.size() / numThreads;
    static size_t valid = 0;
    vector<thread> threads;
    auto start_time = chrono::high_resolution_clock::now(); // <-- Timer starts here
    for (int i = 0; i < numThreads; i++)
    {
        size_t start = i * partSize;
        size_t end;
        if (i == numThreads - 1)
            end = passportStrings.size();
        else
            end = (i + 1) * partSize;
        threads.emplace_back(validCount, ref(passportStrings), ref(valid), start, end);
    }

    for (auto& thread : threads)
        thread.join();

    auto end_time = chrono::high_resolution_clock::now(); // <-- Timer ends here
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    if (numThreads == 1)
        cout << "Threading: Single-threaded" << endl;
    else
        cout << "Threading: Multi-threaded (" << numThreads << " threads)" << endl;
    cout << "Samplesize: " << passportStrings.size() << endl;
    cout << "Valid: " << valid<< endl;
    cout << "Invalid: " << passportStrings.size() - valid << endl;
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}