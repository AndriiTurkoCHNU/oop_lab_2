#include "ConsoleApp.h"

void ConsoleApp::run() {
    cout << "Welcome to the Movie Database!" << endl;

    Database db = Database::readDBFromFile(DATABASE_FILE);

    Menu *menu;

    cout << "Admin? (y/n): ";
    char isAdmin;
    cin >> isAdmin;

    if (isAdmin == 'y') {
        cout << "Enter admin username: ";
        string username;
        cin >> username;
        cout << "Enter admin password: ";
        string password;
        cin >> password;
        Admin admin{username, password};
        Admin::readLoginDataFromFile("../admin.txt");

        if (admin.login()) {
            cout << "Logged in successfully!" << endl;
            cout << "Welcome, " << admin.getUsername() << endl;
        } else {
            cout << "Invalid credentials. Exiting..." << endl;
            return;
        }
        menu = new AdminMenu{admin, db};

    } else if (isAdmin == 'n') {
        cout << "Enter username: ";
        string username;
        cin >> username;

        User user{username};
        cout << "Welcome, " << user.getUsername() << endl;
        menu = new UserMenu{user, db};

    } else {
        cout << "Invalid input. Exiting..." << endl;
        return;
    }

    menu->start();
}
