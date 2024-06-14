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

void User::getInfo() {
    cout << this->username <<" has email - " << this->email << "." << endl;
}

User::User(string username, string password)
        : User{std::move(username), "", std::move(password)} {}


User::User(string username, string email, string password)
    : username{std::move(username)}, email{std::move(email)}, password{std::move(password)} {}

User::User(const User &other)
    : username{other.username}, email{other.email}, password{other.password} {}

User &User::operator=(const User &other) {
    if (this != &other) {
        username = other.username;
        email = other.email;
        password = other.password;
    }

    return *this;
}

User::~User() = default;


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

int MyInt::getValue() const {
    return value;
}

string Critic::getReview(const MyInt& id) {
    return reviews[id.getValue()];
}

void Critic::addReview(const MyInt& id, string review) {
    reviews[id.getValue()] = std::move(review);
}

Critic::Critic(string username, string password, string realName)
    : User(std::move(username), std::move(password)), realName{std::move(realName)} {}

Critic::Critic(string username, string email, string password, string realName)
    : User(std::move(username), std::move(email), std::move(password)), realName{std::move(realName)} {}

Critic::Critic(const Critic &other)
    : User(other), realName{other.realName} {}

Critic &Critic::operator=(const Critic &other) {
    if (this != &other) {
        User::operator=(other);
        realName = other.realName;
    }
    return *this;

}

