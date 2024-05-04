#include <iostream>
#include <list>
#include <string>

class PhonebookEntry {
    char* fullname;
    std::string address{};
    std::string phone{};

    public:
    PhonebookEntry(std::string name, std::string address, std::string phone) : fullname(new char[name.size() + 1]), address(address), phone(phone) {
        name.copy(fullname, name.size());
        fullname[name.size()] = '\0';
    }

    PhonebookEntry(const PhonebookEntry& other) : fullname(other.fullname), address(other.address), phone(other.address) {}

    PhonebookEntry(PhonebookEntry&& other) noexcept : 
        fullname(std::move(other.fullname)),
        address(std::move(other.address)),
        phone(std::move(other.phone)) {}

    ~PhonebookEntry() {
        delete[] fullname;
    }

    void appendEntry(std::list<PhonebookEntry> phonebook) {
        phonebook.push_back(*this);
    }

    void deleteEntry(std::list<PhonebookEntry> phonebook, std::string name) {
        std::list<PhonebookEntry>::iterator it = phonebook.begin();
        for (PhonebookEntry entry : phonebook) {
            if (name == entry.getNameStr()) {
                entry.~PhonebookEntry();
                phonebook.erase(it);
            }
            it++;
        }
    }

    void redact(std::string chName, std::string chAddress, std::string chPhone) {
        address = chAddress;
        phone = chPhone;
        delete[] fullname;
        char* fullname = new char[sizeof(chName) + 1];
        chName.copy(fullname, chName.size());
        fullname[chName.size()] = '\0';
    }

    void search(std::list<PhonebookEntry> phonebook, std::string searchName) {
        for (PhonebookEntry entry : phonebook) {
            if (searchName == entry.getNameStr()) {
                std::cout << "Found!" << std::endl;
                entry.print();
                return;
            }
        }
    }

    std::string getNameStr() {
        return std::string(fullname);
    }

    void print() {
        std::cout << "\t" << fullname << "\n" << address << "\n" << phone << std::endl; 
    }
};

int main() {
    std::list<PhonebookEntry> phonebook;

    PhonebookEntry entry1{"Vasya", "Moscow, Lenina str., apt 29", "+79998887766"};
    PhonebookEntry entry2{ "Kolya", "St. Petersburg, Pushkina str., apt 11", "+70001112233" };
    
    entry1.print();
    entry2.print();
    phonebook.push_back(std::move(entry1));
    phonebook.push_back(std::move(entry2));

    entry1.print();
    entry2.print();
    //entry2.redact("Kolya", "London, Main str., apt 11", "+10001112233");
    //entry2.print();

    return 0;
}