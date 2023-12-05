#include <string>

class Passport
{
public:
    Passport() {}
    void setByr(std::string byr) { this->byr = std::stoi(byr); }
    void setIyr(std::string iyr) { this->iyr = std::stoi(iyr); }
    void setEyr(std::string eyr) { this->eyr = std::stoi(eyr); }
    void setCid(std::string cid) { this->cid = std::stoi(cid); }
    void setHgt(std::string hgt) { this->hgt = hgt; }
    void setHcl(std::string hcl) { this->hcl = hcl; }
    void setEcl(std::string ecl) { this->ecl = ecl; }
    void setPid(std::string pid) { this->pid = pid; }
    void setValid(bool valid) { this->valid = valid; }
    std::string toString()
    {
        return "byr: " + std::to_string(byr) + " iyr: " + std::to_string(iyr) + " eyr: " + std::to_string(eyr) + " cid: " + std::to_string(cid) + " hgt: " + hgt + " hcl: " + hcl + " ecl " + ecl + " pid: " + pid;
    }

private:
    int byr;
    int iyr;
    int eyr;
    int cid; // optional
    std::string hgt;
    std::string hcl;
    std::string ecl;
    std::string pid;
    bool valid;
};