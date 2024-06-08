#include "movie_database.h"

#include <utility>
#include <limits>

int Movie::generalId = 0;

void Movie::getInfo() {
    cout << "Movie: \"" << title << "\" was released in " << releaseYear << ", "
    << "directed by " << director << ". Rating: " << rating << endl;
}

void Movie::updateRating(float newRating) {
    rating = newRating;
    cout << title <<" has new rating: " << rating << endl;
}

Movie::Movie(string title, int releaseYear, string director)
    : Movie{std::move(title), 0, releaseYear, std::move(director)} {}

Movie::Movie(string title, float rating, int releaseYear, string director)
    : id{getId()}, title{std::move(title)}, rating{rating}, releaseYear{releaseYear}, director{std::move(director)} {}

int Movie::getId() {
    generalId++;

    return generalId;
}

Movie::~Movie() = default;

void User::getInfo() {
    cout << username <<" has email - " << email << "." << endl;
}

User::User(string username, string password)
        : User{std::move(username), "", std::move(password)} {}


User::User(string username, string email, string password)
    : username{std::move(username)}, email{std::move(email)}, password{std::move(password)} {}

User::~User() = default;

bool DatabaseConnection::connect(const string& username, const string& password) {
    cout << "Trying to connect to " << host << " ..." << endl;
    string maskedPassword(password.size(), '*');
    cout << "Password \"" << maskedPassword << "\" for " << username <<  " is incorrect." << endl;
    return false;
}

void DatabaseConnection::changeHost(string newHost) {
    host = std::move(newHost);
    cout << "New host: " << host << endl;
}

DatabaseConnection::DatabaseConnection(string host)
    : host{std::move(host)} {}

DatabaseConnection::~DatabaseConnection() = default;
