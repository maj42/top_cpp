#include <iostream>

using namespace std;

enum Genre {
    action, comedy, thriller
};

string genrePrint(Genre);

struct VideoStore {
    string name;
    string director;
    Genre genre;
    float rating;
    float price;

    void print() {
        cout << "Film: " << name << endl;
        cout << "Director: " << director << endl;
        cout << "Genre: " << genrePrint(genre) << endl;
        cout << "Film rating: " << rating << endl;
        cout << "Price of film: " << price << endl << endl;
    }
};

void nameSearch(VideoStore*, int, string);
void directorSearch(VideoStore*, int, string);
void genreSearch(VideoStore*, int, Genre);
void mostPopularSearch(VideoStore*, int);
void addFilm(VideoStore*&, int&, string, string, Genre, float, float);
void delFilm(VideoStore*&, int&, int);

int main()
{
    string nameArr[3]{ "Ace Ventura", "Iron Man", "Titanic" };
    string dirArr[3]{ "Tom Shadyac", "Jon Favreau", "James Cameron" };
    Genre genreArr[3]{ comedy, action, thriller };
    float rateArr[3]{ 6.9, 7.9, 8 };
    float priceArr[3]{ 100.99, 89.99, 111.49 };
    int size = 3;
    VideoStore* films{ new VideoStore[size] };
    for (int i = 0; i < size; ++i) {
        VideoStore temp{ nameArr[i], dirArr[i], genreArr[i], rateArr[i], priceArr[i] };
        films[i] = temp;
    }

    for (int i = 0; i < size; ++i) {
        films[i].print();
    }

    //nameSearch(films, size, "Iron Man 2");
    //directorSearch(films, size, "Joss Wheadon");
    //genreSearch(films, size, thriller);
    //mostPopularSearch(films, size);

    cout << "Adding a film: " << endl;
    addFilm(films, size, "Jaws", "Steven Spielberg", thriller, 8.1, 105.99);

    for (int i = 0; i < size; ++i) {
        films[i].print();
    }

    cout << "Deleting a film: " << endl;
    delFilm(films, size, 1);

    for (int i = 0; i < size; ++i) {
        films[i].print();
    }
    
    delete[] films;
}

string genrePrint(Genre genre) {
    switch (genre) {
    case 0: return "action";
    case 1: return "comedy";
    case 2: return "thriller";
    }
}

void nameSearch(VideoStore* films, int size, string name) {
    for (int i = 0; i < size; ++i) {
        if (films[i].name == name) {
            cout << "Found film!" << endl;
            films[i].print();
            cout << endl;
            return;
        }
    }
    cout << "Film " << name << " not found" << endl << endl;
}
void directorSearch(VideoStore* films, int size, string director) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (films[i].director == director) {
            found = true;
            cout << "Found film with director " << director << endl;
            films[i].print();
            cout << endl;
        }
    }
    if (!found) cout << "Films with this director not found" << endl << endl;
}

void genreSearch(VideoStore* films, int size, Genre genre) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (films[i].genre == genre) {
            found = true;
            cout << "Found film of genre " << genrePrint(genre) << endl;
            films[i].print();
            cout << endl;
        }
    }
    if (!found) cout << "Films of this genre not found" << endl << endl;
}

void mostPopularSearch(VideoStore* films, int size) {
    float maxRate = 0;
    int maxInd = 0;
    for (int i = 0; i < size; ++i) {
        if (films[i].rating > maxRate) {
            maxInd = i;
        }
    }
    cout << "Most popular film: " << films[maxInd].name << endl << endl;
    films[maxInd].print();
    cout << endl;
}

void addFilm(VideoStore*& films, int& size, string name, string director, Genre genre, float rating, float price) {
    VideoStore* newFilms = new VideoStore[size + 1];
    for (int i = 0; i < size; ++i) newFilms[i] = films[i];
    newFilms[size++] = VideoStore{ name, director, genre, rating, price };
    delete[] films;
    films = newFilms;
}

void delFilm(VideoStore*& films, int& size, int ind) {
    if (ind >= size) {
        cout << "Index not in range" << endl;
        return;
    }
    VideoStore* newFilms = new VideoStore[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i == ind) continue;
        newFilms[j++] = films[i];
    }
    delete[] films;
    size--;
    films = newFilms;
}