#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include "User.h"
#include "Database.h"


class Menu {
public:
    virtual void start() = 0;
    virtual void options() = 0;
};

class UserMenu: public Menu {
private:
    User user;
    Database db;
    vector<int> logHistory;

    void saveLog();
public:
    UserMenu(const User& user, const Database& db);

    void start() override;
    void options() override;

};

class AdminMenu: public Menu {
private:
    Admin admin;
    Database db;
public:
    AdminMenu(Admin admin, const Database &db);

    void start() override;
    void options() override;
};


#endif //LAB2_MENU_H
