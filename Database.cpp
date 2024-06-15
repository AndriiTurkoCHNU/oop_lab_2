#include "Database.h"


Database::Database() = default;

Database::Database(const Database &other)
    : movies{other.movies} {}

void Database::addMovie(const Movie& movie) {
    this->movies.push_back(movie);
}

size_t Database::countMovies() {
    return this->movies.size();
}

Database::~Database() = default;

void Database::flushDB() {
    movies.clear();
    cout << "Database flushed." << endl;
}
