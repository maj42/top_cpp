#include <iostream>
#include <vector>

class PhonebookEntry {
    char* fullname;
    std::string address{};
    std::string phone{};

    public:
    PhonebookEntry(std::string name, std::string address, std::string phone) : fullname(new char[sizeof(name)]), address(address), phone(phone) {
        name.copy(fullname, name.size());
    }

    ~PhonebookEntry() {
        delete[] fullname;
    }

    void create(std::Vector<PhonebookEntry> phonebook, std::string crName, std::address crAddress, std::string crPhone) {
        phonebook.push_back(PhonebookEntry(crName, crAddress, crPhone));
    }

    void delete(std::Vector<PhonebookEntry> phonebook, int ind) {
        phonebook[ind]->~PhonebookEntry();
        phonebook[ind].erase(); 
    }

    void redact(std::string chName, std::address chAddress, std::string chPhone) {
        address = chAddress;
        phone = chPhone;
        delete[] fullname;
        char* fullname = new char[sizeof(chName)];
        chName.copy(fullname, name.size());
    }

    //search
    void search(std::string searchName) {

    }

    void print() {
        std::cout << "\t" << fullname << "\n" << address << "\n" << phone << std::endl; 
    }
};

int main() {
    PhonebookEntry entr{"Vasya", "Moscow, Lenina str., apt 29", "+79998887766"};
    entr.print();

    return 0;
}