#include "User.h"
#include <utility>

map<string, string> Admin::loginData;


User::User(string username)
        : User{std::move(username), ""} {}

User::User(string username, string email)
        : username{std::move(username)}, email{std::move(email)} {}

User::User(const User &other)
        : username{other.username}, email{other.email} {}

User &User::operator=(const User &other) {
    if (this != &other) {
        username = other.username;
        email = other.email;
    }
    return *this;
}

User::~User() = default;

void User::displayProfile() {
    cout << "Displaying profile for user " << username << "\n" << endl;
}

string User::getUsername() {
    return username;
}

string Critic::getReview(const int& id) {
    return reviews[id];
}

void Critic::addReview(const int& id, string review) {
    reviews[id] = std::move(review);
}

Critic::Critic(string username, string email, string realName)
        : User(std::move(username), std::move(email)), realName{std::move(realName)} {}

Critic::Critic(const Critic &other)
        : User(other), realName{other.realName}, reviews{other.reviews} {}

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

void Critic::displayProfile()  {
    cout << "Displaying profile for Critic: " << username << endl;
    if (!email.empty())
        cout << "Email: " << email << endl;
    cout << endl;
}

map<int, string> Critic::getReviews() {
    return reviews;
}

string Critic::getRealName() {
    return realName;
}


string Critic::getEmail() {
    return email;
}

Critic Critic::createCritic() {
    string username, email, realName;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter real name: ";
    cin >> realName;

    return {username, email, realName};
}

Admin::Admin(string username, string password)
    : User(std::move(username)), password{std::move(password)} {}

void Admin::displayProfile() {
    cout << "Displaying profile for admin " << username << "\n" << endl;
}

void Admin::readLoginDataFromFile(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password;

        if (!getline(ss, username, ':') || !getline(ss, password, ':')) {
            cerr << "Invalid line format in file " << filename << endl;
            continue;
        }

        Admin::loginData[username] = password;
    }

    file.close();
}

bool Admin::login() {
    return loginData.find(username) != loginData.end() && loginData[username] == password;
}
