#include <iostream>
#include <list>

class Book {
    std::string name;
    std::string author;
    int year;

    friend class Library;
    friend std::ostream& operator<<(std::ostream& os, Book book);
public:
    Book(std::string name, std::string author, int year) : name(name), author(author), year(year) {}

    inline bool matches(const std::string& pattern) const {
        return name.find(pattern) != std::string::npos || author.find(pattern) != std::string::npos;
    }
};

std::ostream& operator<<(std::ostream& os, Book book) {
    os << "Book: " << book.name << "\nAuthor: " << book.author << "\nYear of publishing: " << book.year << "\n";
    return os;
}

class Library {
    std::list<Book> list;

public:
    Library& operator+=(Book& book) {
        list.push_back(book);
        return *this;
    }

    void operator-=(std::string&& pattern) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            if ((*it).matches(pattern)) {
                list.erase(it);
                return;
            }
        }
        std::cout << "Not found" << "\n";
    }

    void search(std::string pattern) {
        for (Book book : list) {
            if (book.author.find(pattern) != std::string::npos) {
                std::cout << book;
                return;
            }
        }
        std::cout << "Book with author \"" << pattern << "\" not found" << "\n";
    }
};

template<class T>
T max(T* arr, size_t size) {
    T temp = arr[0];
    for (int i = 0; i < size; ++i) {
        if (arr[i] > temp) temp = arr[i];
    }
    return temp;
}

template<class T>
T min(T* arr, size_t size) {
    T temp = arr[0];
    for (int i = 0; i < size; ++i) {
        if (arr[i] < temp) temp = arr[i];
    }
    return temp;
}

//bubble sort
template<class T>
void sort(T* arr, size_t size) {
    T temp;
    for (int i = size; i != 0; --i) {
        for (int j = 0; j < size - i; ++j) {
            if (arr[j] > arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main()
{
    // Templates
    int intArr[3]{ 2, 1, 3 };
    std::cout << "Max is " << max(intArr, 3) << std::endl;
    std::cout << "Min is " << min(intArr, 3) << std::endl;
    sort(intArr, 3);
    std::cout << "Sorted: ";
    for (int i = 0; i < 3; ++i) std::cout << intArr[i] << " ";
    std::cout << std::endl;

    // Library
    Book book1{ "Zen and the Art of Motorcycle Maintenance", "Robert M. Pirsig", 1974 };

    Library lib;

    lib += book1;

    lib.search("Rob");
    lib -= "Zen";
    lib.search("Rob");

    return 0;
}