#include "Watch.h"

#include <utility>


MyInt Movie::generalId = 0;

void Movie::getInfo() {
    cout << "Movie: \"" << title << "\" was released in " << *releaseYear << ", "
         << "directed by " << director << ". Rating: " << rating << "\n" << endl;
}

void Movie::updateRating(float newRating) {
    rating = newRating;
    cout << title <<" has new rating: " << rating << "\n" << endl;
}

Movie::Movie(string title, int releaseYear, string director)
        : Movie{std::move(title), 0, releaseYear, std::move(director)} {}

Movie::Movie(string title, float rating, int rYear, string director)
        : id{getGenId()}, title{std::move(title)}, rating{rating}, director{std::move(director)}
{
    releaseYear = new int;
    *releaseYear = rYear;
}

MyInt Movie::getGenId() {
    return generalId++;
}

//Copy constructor
Movie::Movie(const Movie &other)
        : Movie{ other.title, other.rating, *other.releaseYear, other.director } {}

//Move constructor
Movie::Movie(Movie &&other)
        : title{other.title}, rating{other.rating}, releaseYear{other.releaseYear}, director{other.director}
{
    other.releaseYear = nullptr;
}

Movie::~Movie() { delete releaseYear; }

MyInt Movie::getCurrentGeneralId() {
    return generalId;
}

MyInt Movie::getId() {
    return this->id;
}

void Series::getInfo() {
    cout << title << " was released in " << releaseYear << " by " << production << ".\n"
    << "Its rating " << rating << ". " << "Now it has " << seasons << " seasons." << endl;
}

Series::Series(string title, float rating, int releaseYear, int seasons, string production)
    : title{std::move(title)}, rating{rating}, releaseYear{releaseYear},
    seasons{seasons}, production{std::move(production)} {}
