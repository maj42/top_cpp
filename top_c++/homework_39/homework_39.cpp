#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>
#include <string>

class PhonebookEntry {
    char* fullname;
    std::string address{};
    std::string phone{};

    public:
    PhonebookEntry(std::string name, std::string address, std::string phone) : fullname(new char[name.size() + 1]), address(address), phone(phone) {
        strcpy(fullname, name.c_str());
    }

    PhonebookEntry(const PhonebookEntry& other) :
        fullname(new char[strlen(other.fullname)]),
        address(other.address),
        phone(other.phone) {
        strcpy(fullname, other.fullname);
    }

    ~PhonebookEntry() {
        if (fullname != nullptr) delete[] fullname;
    }

    void deleteEntry(std::list<PhonebookEntry>& phonebook, std::string name) {
        std::list<PhonebookEntry>::iterator it = phonebook.begin();
        for (PhonebookEntry& entry : phonebook) {
            if (name == entry.getNameStr()) {
                phonebook.erase(it);
            }
            it++;
        }
    }

    void redact(const std::string& chName, const std::string& chAddress, const std::string& chPhone) {
        address = chAddress;
        phone = chPhone;
        delete[] fullname;
        fullname = new char[chName.size() + 1];
        strcpy(fullname, chName.c_str());
    }

    void search(std::list<PhonebookEntry>& phonebook, std::string searchName) {
        for (PhonebookEntry entry : phonebook) {
            if (searchName == entry.getNameStr()) {
                std::cout << "Found!" << std::endl;
                entry.print();
                return;
            }
            std::cout << "Not found" << std::endl;
        }
    }

    std::string getNameStr() const {
        return std::string(fullname);
    }

    void print() const {
        std::cout << "\t" << fullname << "\n" << address << "\n" << phone << std::endl; 
    }
};

int main() {
    std::list<PhonebookEntry> phonebook;

    PhonebookEntry entry1{"Vasya", "Moscow, Lenina str., apt 29", "+79998887766"};
    PhonebookEntry entry2{ "Kolya", "St. Petersburg, Pushkina str., apt 11", "+70001112233" };
    entry1.print();
    entry2.redact("Kolya", "London, Main str., apt 11", "+10001112233");
    entry2.print();
    phonebook.push_back(entry1);
    phonebook.push_back(entry2);

    return 0;
}