#ifndef LAB2_USER_H
#define LAB2_USER_H

#include <iostream>
#include <map>
#include "helpers.h"

using namespace std;


class User {
protected:
    string username;
    string email;
    string password;
public:
    void getInfo();
    User(string username, string password);
    User(string username, string email, string password);

    User(const User &other);

    virtual ~User();

    User &operator=(const User &other);

    virtual bool authenticate(const string &password);

    virtual void displayProfile();
};

class Critic: public User {
private:
    string realName;
    map<int, string> reviews;
public:
    Critic(string username, string password, string realName);
    Critic(string username, string email, string password, string realName);

    Critic(const Critic &other);

    Critic &operator=(const Critic &other);

    string getReview(const MyInt& id);
    void addReview(const MyInt& id, string review);
    size_t countReviews();

    void getInfo();

    bool authenticate(const string &password) override;
    void displayProfile() override;
};


#endif //LAB2_USER_H
