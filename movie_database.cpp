#include "movie_database.h"

#include <utility>

MyInt Movie::generalId = 0;

void Movie::getInfo() {
    cout << "Movie: \"" << title << "\" was released in " << *releaseYear << ", "
    << "directed by " << director << ". Rating: " << rating << endl;
}

void Movie::updateRating(float newRating) {
    rating = newRating;
    cout << title <<" has new rating: " << rating << endl;
}

Movie::Movie(string title, int releaseYear, string director)
    : Movie{std::move(title), 0, releaseYear, std::move(director)} {}

Movie::Movie(string title, float rating, int rYear, string director)
    : id{getId()}, title{std::move(title)}, rating{rating}, director{std::move(director)}
    {
        releaseYear = new int;
        *releaseYear = rYear;
    }

MyInt Movie::getId() {
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

void User::getInfo() {
    cout << this->username <<" has email - " << this->email << "." << endl;
}

User::User(string username, string password)
        : User{std::move(username), "", std::move(password)} {}


User::User(string username, string email, string password)
    : username{std::move(username)}, email{std::move(email)}, password{std::move(password)} {}

User::User(const User &other)
    : username{other.username}, email{other.email}, password{other.password} {}

User::~User() = default;

bool DatabaseConnection::connect(const string& username, const string& password) {
    cout << "Trying to connect to " << this->host << " ..." << endl;
    string maskedPassword(password.size(), '*');
    cout << "Password \"" << maskedPassword << "\" for " << username <<  " is incorrect." << endl;
    return false;
}

void DatabaseConnection::changeHost(string newHost) {
    this->host = std::move(newHost);
    cout << "New host: " << this->host << endl;
}

string DatabaseConnection::getHost() const {
    return this->host;
}

DatabaseConnection::DatabaseConnection(string host)
    : host{std::move(host)} {}

DatabaseConnection::DatabaseConnection(const DatabaseConnection &other)
    : host{other.host} {}

DatabaseConnection::~DatabaseConnection() = default;

MyInt::MyInt(int value)
    : value{value} {}

MyInt::MyInt(const MyInt &other)
    : value{other.value} {}

MyInt MyInt::operator++(int) {
    MyInt temp = *this;
    ++value;
    return temp;
}

MyInt MyInt::operator+(const MyInt &other) const {
    return {value + other.value};
}

std::ostream& operator<<(std::ostream& os, const MyInt& obj) {
    os << obj.value;
    return os;
}

std::istream& operator>>(std::istream& is, MyInt& obj) {
    is >> obj.value;
    return is;
}

