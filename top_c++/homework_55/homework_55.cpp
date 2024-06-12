#include <iostream>

class Passport {
public:
    unsigned long long ID;
    std::string name;
    std::string birthDate;
    std::string citizenship;

    Passport(unsigned long long id, std::string name, std::string birthDate, std::string citizenship) : name(name), birthDate(birthDate), citizenship(citizenship) {
        while (id > 9999999999) {
            id /= 10;
        }
        this->ID = id;
    }
};

std::ostream& operator<<(std::ostream& str, const Passport& pass) {
    str << "ID: " << pass.ID << "\nName: " << pass.name << "\nBirth Date: " << pass.birthDate << "\nCityzenship: " << pass.citizenship;
    return str;
}

class InternPass : public Passport {
public:
    unsigned long IPID;
    std::string visa;

    InternPass(unsigned long long ID, std::string name, std::string birthDate, std::string citizenship, unsigned long long IPID, std::string visa) :
        Passport(ID, name, birthDate, citizenship), IPID(IPID), visa(visa) {}

    InternPass(Passport& pass, unsigned long long IPID, std::string visa) : Passport(pass.ID, pass.name, pass.birthDate, pass.citizenship),
        IPID(IPID), visa(visa) {}
};

std::ostream& operator<<(std::ostream& str, const InternPass& pass) {
    Passport const* innerPass = &pass;
    str << std::endl << *innerPass << "\nInternational Passport ID: " << pass.IPID << "\nVisa: " << pass.visa;
    return str;
}

InternPass makeInternational(Passport& pass) {
    return InternPass(pass, 0, "default visa");
}

int main()
{
    Passport pass(12345678910, "Vasya", "1.1.1970", "Kenya");
    InternPass multipass(12345, "Lilu Dallas", "10.10.2263", "Mondochivan", 54321, "interplanetary");

    std::cout << pass << std::endl;
    std::cout << multipass << std::endl;

    InternPass intPass = makeInternational(pass);
    std::cout << intPass << std::endl;
}