#include <iostream>
#include <vector>
#include <memory>

class Document {
public:
    std::string name;
    std::string author;
    std::string creationDate;

    Document(std::string name, std::string author, std::string creationDate) : name(name), author(author), creationDate(creationDate) {}

    void print() const {
        std::cout << name << " printed." << std::endl;
    }

    void send(std::string to) const {
        std::cout << name << " sent to " << to << std::endl;
    }

    virtual void info() const = 0;
};

class Report : public Document {
public:
    Report(std::string name, std::string author, std::string creationDate, int pages) : Document(name, author, creationDate), pages(pages) {}

    int pages;

    void info() const override {
        std::cout << name << ":\n\t" << author << "\n\t" << creationDate << "\n\tPages: " << pages << std::endl;
    }
};

class Contract : public Document {
public:
    Contract(std::string name, std::string author, std::string creationDate, int sum) : Document(name, author, creationDate), sum(sum) {}
    int sum;

    void info() const override {
        std::cout << name << ":\n\t" << author << "\n\t" << creationDate << "\n\tContract sum: " << sum << std::endl;
    }
};

class Letter : public Document {
public:
    Letter(std::string name, std::string author, std::string creationDate, std::string recepient) : Document(name, author, creationDate), recepient(recepient) {}
    std::string recepient;

    void info() const override {
        std::cout << name << ":\n\t" << author << "\n\t" << creationDate << "\n\tLetter sent to: " << recepient << std::endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<Document>> documents;
    documents.emplace_back(std::make_unique<Report> ( "Report", "Vasya", "1.01.2001", 10 ));
    documents.emplace_back(std::make_unique<Contract> ("Contract", "Vasya", "2.01.2001", 1000000 ));
    documents.emplace_back(std::make_unique<Letter>( "Letter", "Vasya", "3.01.2001", "Masha"));

    for (const std::unique_ptr<Document>& doc : documents) {
        doc->info();
    }
}
