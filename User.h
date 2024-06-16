#ifndef LAB2_USER_H
#define LAB2_USER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;


class User {
protected:
    string username;
    string email;
public:
    User(string username);
    User(string username, string email);

    User(const User &other);

    virtual ~User();

    User &operator=(const User &other);

    virtual void displayProfile();

    string getUsername();
};

class Critic: public User {
private:
    string realName;
    map<int, string> reviews;
public:
    Critic(string username, string password, string realName);

    Critic(const Critic &other);

    Critic &operator=(const Critic &other);

    string getReview(const int& id);
    void addReview(const int& id, string review);
    size_t countReviews();

    void displayProfile() override;
    map<int, string> getReviews();
    string getRealName();
    string getEmail();

    static Critic createCritic();
};

class Admin: public User {
private:
    string password;
    static map<string, string> loginData;
public:
    Admin(string username, string password);

    void displayProfile() override;

    static void readLoginDataFromFile(const string& filename);
    bool login();
};


#endif //LAB2_USER_H
