#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

class PhoneBase {
public:
    std::unordered_map<std::string, std::string> addrBook;

    PhoneBase() : addrBook{} {}

    void addEntry(std::string name, std::string phone) {
        addrBook[name] = phone;
    }

    void deleteEntry(std::string name) {
        addrBook.erase(name);
    }

    void modifyEntry(std::string name, std::string newPhone) {
        addrBook[name] = newPhone;
    }

    void searchByName(std::string name) const {
        for (auto search = addrBook.begin(); search != addrBook.end(); search++) {
            if (search->first == name) {
                std::cout << "Found " << search->first << ' ' << search->second << '\n';
            }
        }
    }

    void searchByPhone(std::string phone) const {
        for (auto search = addrBook.begin(); search != addrBook.end(); ++search) {
            if (search->second == phone) {
                std::cout << "Found " << search->first << ' ' << search->second << '\n';
            }
        }
    }

    friend std::ofstream;
    friend std::ifstream;
};

std::ifstream& operator>>(std::ifstream& str, PhoneBase& phBase) {
    std::string key, value;

    while (str >> key >> value) {
        phBase.addEntry(key, value);
    }
    return str;
}

std::ofstream& operator<<(std::ofstream& str, PhoneBase& phBase) {
    for (auto it = phBase.addrBook.begin(); it != phBase.addrBook.end(); it++) {
        str << it->first << " " << it->second << std::endl;
    }
    return str;
}

void savePhoneBaseToFile(PhoneBase& phBase, std::string fileName) {
    std::ofstream file{ fileName, std::ios::app };

    if (file.is_open()) {
        file << phBase;
    }

    file.close();
}

void loadPhoneBaseFromFile(PhoneBase& phBase, std::string fileName) {
    std::ifstream file{ fileName };

    if (file.is_open()) {
        file >> phBase;
    }

    file.close();
}

int main()
{
    PhoneBase phB;
    phB.addEntry("Vasya", "123345");
    phB.addEntry("Kolya", "345546");
    phB.addEntry("Masha", "988765");
    phB.searchByName("Vasya");
    phB.searchByPhone("123345");
    phB.modifyEntry("Kolya", "456654");
    phB.deleteEntry("Kolya");
    savePhoneBaseToFile(phB, "PhoneBase.txt");

    PhoneBase newPhB;
    loadPhoneBaseFromFile(newPhB, "PhoneBase.txt");
    newPhB.searchByName("Vasya");

}