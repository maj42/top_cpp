#include <iostream>
#include <cstring>

class Date {
    uint16_t day;
    uint16_t month;
    uint16_t year;
public:
    Date(uint16_t day, uint16_t month, uint16_t year) : day(day), month(month), year(year) {}
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

    void setDay(uint16_t& newDay) {
        day = newDay;
    }

    void setMonth(uint16_t& newMonth) {
        month = newMonth;
    }

    void setYear(uint16_t& newYear) {
        year = newYear;
    }

    void print() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

class Human {
    int ID;
    char* firstName;
    char* lastName;
    char* partonymic;
    Date date;

public:
    static int count;

    Human(int ID, const std::string& firstNameStr, const std::string& lastNameStr, const std::string& partonymicStr, uint16_t day, uint16_t month, uint16_t year) :
        ID(ID), firstName(new char[firstNameStr.size() + 1]), lastName(new char[lastNameStr.size() + 1]), partonymic(new char[partonymicStr.size() + 1]),
        date{ day, month, year } {
        strcpy(firstName, firstNameStr.c_str());
        strcpy(lastName, lastNameStr.c_str());
        strcpy(partonymic, partonymicStr.c_str());
        count++;
    }

    Human() : Human(0, "DefaultFirstName", "DefaultLastName", "DefaultPartonymic", 1, 1, 1970) {};
    Human(const Human& other) : ID(other.ID), date{ other.date } {
        size_t firstSize = strlen(other.firstName);
        this->firstName = new char[firstSize + 1];
        strcpy(firstName, other.firstName);
        size_t lastSize = strlen(other.lastName);
        this->lastName = new char[lastSize + 1];
        strcpy(lastName, other.lastName);
        size_t partonymicSize = strlen(other.partonymic);
        this->partonymic = new char[partonymicSize + 1];
        strcpy(partonymic, other.partonymic);
    }

    ~Human() {
        if (firstName != nullptr) delete[] firstName;
        if (lastName != nullptr) delete[] lastName;
        if (partonymic != nullptr) delete[] partonymic;
        count--;
    }

    static int getCount() {
        return count;
    }

    int getID() {
        return ID;
    }

    void setID(int newID) {
        ID = newID;
    }

    void setFirstName(const std::string& nameStr) {
        delete[] firstName;
        firstName = new char[nameStr.size() + 1];
        strcpy(firstName, nameStr.c_str());
    }

    void setLastName(const std::string& nameStr) {
        delete[] lastName;
        lastName = new char[nameStr.size() + 1];
        strcpy(lastName, nameStr.c_str());
    }


    void setPartonymic(const std::string& nameStr) {
        delete[] partonymic;
        partonymic = new char[nameStr.size() + 1];
        strcpy(partonymic, nameStr.c_str());
    }

    const Date& getDate() const{
        return date;
    }

    void setDate(uint16_t day, uint16_t month, uint16_t year) {
        date.setDay(day);
        date.setMonth(month);
        date.setYear(year);
    }

    void print() const {
        std::cout << "ID: " << ID << "\n" << firstName << " " << partonymic << " " << lastName << "\nBirthdate: ";
        date.print();
        std::cout << "Humans: " << count << std::endl << std::endl;
    }
};

int Human::count = 0;

int main()
{
    Human defaultHuman{};
    Human vasya{ 123, "Vasya", "Pupkin", "Vasylievich", 10, 10, 1999 };
    defaultHuman.setID(321);
    defaultHuman.setFirstName("Kolya");
    defaultHuman.setPartonymic("Nicolaevich");
    defaultHuman.setLastName("Nicolaev");
    defaultHuman.setDate(12, 12, 1993);
    defaultHuman.print();
    vasya.print();
    defaultHuman.getDate().print();

    return 0;
}