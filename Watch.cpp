#include "Watch.h"

#include <utility>


void Movie::getInfo() {
    cout << "Movie \"" << title << "\" was released in " << *releaseYear << ", "
         << "directed by " << director << ". Rating: " << rating << "\n" << endl;
}

void Movie::updateRating(float newRating) {
    rating = newRating;
    cout << title <<" has new rating: " << rating << "\n" << endl;
}

Movie::Movie(int id, string title, int releaseYear, string director)
        : Movie{id, std::move(title), 0, releaseYear, std::move(director)} {}

Movie::Movie(int id, string title, float rating, int rYear, string director)
        : id{id}, title{std::move(title)}, rating{rating}, director{std::move(director)}
{
    releaseYear = new int;
    *releaseYear = rYear;
}

//Copy constructor
Movie::Movie(const Movie &other)
        : Movie{ other.id, other.title, other.rating, *other.releaseYear, other.director } {}

//Move constructor
Movie::Movie(Movie &&other)
        : id{other.id}, title{other.title}, rating{other.rating}, releaseYear{other.releaseYear}, director{other.director}
{
    other.releaseYear = nullptr;
}

Movie::~Movie() { delete releaseYear; }

int Movie::getId() const {
    return this->id;
}

string Movie::getTitle() {
    return title;
}

Movie Movie::createMovie() {
    int id;
    string title;
    float rating;
    int releaseYear;
    string director;

    cout << "Enter id: ";
    cin >> id;
    cin.ignore();
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter rating: ";
    cin >> rating;
    cout << "Enter release year: ";
    cin >> releaseYear;
    cin.ignore();
    cout << "Enter director: ";
    getline(cin, director);

    return {id, title, rating, releaseYear, director};
}

float Movie::getRating() const {
    return rating;
}

int Movie::getReleaseYear() {
    return *releaseYear;
}

string Movie::getDirector() {
    return director;
}

void Series::getInfo() {
    cout << "Series \"" << title << "\" was released in " << releaseYear << " by " << production << ".\n"
    << "Its rating " << rating << ". " << "Now it has " << seasons << " seasons.\n" << endl;
}

Series::Series(string title, float rating, int releaseYear, int seasons, string production)
    : title{std::move(title)}, rating{rating}, releaseYear{releaseYear},
    seasons{seasons}, production{std::move(production)} {}

Series Series::createSeries() {
    string title;
    float rating;
    int releaseYear;
    int seasons;
    string production;

    cin.ignore();
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter rating: ";
    cin >> rating;
    cout << "Enter release year: ";
    cin >> releaseYear;
    cout << "Enter number of seasons: ";
    cin >> seasons;
    cin.ignore();
    cout << "Enter production: ";
    getline(cin, production);

    return {title, rating, releaseYear, seasons, production};
}

string Series::getTitle() {
    return title;
}

float Series::getRating() const {
    return rating;
}

int Series::getReleaseYear() const {
    return releaseYear;
}

int Series::getSeasons() const {
    return seasons;
}

string Series::getProduction() {
    return production;
}
