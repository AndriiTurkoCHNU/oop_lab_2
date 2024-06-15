#include "User.h"

void User::getInfo() {
    if (!email.empty())
        cout << "User " << this->username <<" has email - " << this->email << ".\n" << endl;
    else
        cout << "User " << this->username <<" does not have an email.\n" << endl;
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

bool User::authenticate(const string &pass) {
    return this->password == pass;
}

void User::displayProfile() {
    cout << "Displaying profile for user " << username << "\n" << endl;
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

size_t Critic::countReviews() {
    return reviews.size();
}

void Critic::getInfo() {
    if (!email.empty())
        cout << "Critic " << this->username <<" has email - " << this->email << "." << endl;
    else
        cout << "Critic " << this->username <<" does not have an email." << endl;
    cout << "Critic has " << this->countReviews() <<  " reviews.\n" << endl;
}

bool Critic::authenticate(const string &pass) {
    if (pass == this->password) {
        cout << "Critic authenticated successfully." << endl;
        return true;
    } else {
        cout << "Authentication failed for Critic." << endl;
        return false;
    }
}

void Critic::displayProfile()  {
    cout << "Displaying profile for Critic: " << username << endl;
    if (!email.empty())
        cout << "Email: " << email << endl;
    cout << endl;
}
