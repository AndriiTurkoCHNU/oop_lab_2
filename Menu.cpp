#include "Menu.h"

#include <utility>

UserMenu::UserMenu(const User& user, const Database& db)
    : user{user}, db{db} {}

void UserMenu::start() {
    int choice;
    do {
        options();
        cout << "Enter your choice: ";
        cin >> choice;
        logHistory.push_back(choice);
        switch (choice) {
            case 1:
                user.displayProfile();
                break;
            case 2:
                db.displayMovies();
                break;
            case 3:
                db.displaySeries();
                break;
            case 4:
                db.displayReviews();
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
    saveLog();
    cout << "Exiting...\n";
}

void UserMenu::options() {
    cout << "Options for user " << user.getUsername() << endl;
    cout << "1. Display profile\n";
    cout << "2. See movies\n";
    cout << "3. See series\n";
    cout << "4. See reviews\n";
    cout << "5. Exit\n";
}

void UserMenu::saveLog() {
    try {
        ofstream file(LOG_FILE, ios::app);
        if (!file.is_open()) {
            throw runtime_error("Could not open file log.txt");
        }
        file << "User " << user.getUsername() << " log history: ";
        for (int choice : logHistory) {
            file << choice << " ";
        }
        file << "\nLogged out at " << currentLocalDateTime();

        file << endl;
        file.close();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

AdminMenu::AdminMenu(Admin admin, const Database& db)
    : admin{std::move(admin)}, db{db} {}

void AdminMenu::start() {
    int choice;
    try {
        do {
            options();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    admin.displayProfile();
                    break;
                case 2:
                    db.displayMovies();
                    break;
                case 3:
                    db.displaySeries();
                    break;
                case 4:
                    db.displayReviews();
                    break;
                case 5:
                    db.addMovie(Movie::createMovie());
                    break;
                case 6:
                    db.addSeries(Series::createSeries());
                    break;
                case 7:
                    db.addCritic(Critic::createCritic());
                    break;
                case 8:
                    db.addReviewForCritic();
                    break;
                case 9:
                    db.flushDB();
                    break;
                case 10:
                    break;
                default:
                    cout << "Invalid choice\n";
            }
        } while (choice != 10);
        cout << "Exiting...\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void AdminMenu::options() {
    cout << "Options for admin " << admin.getUsername() << endl;
    cout << "1. Display profile\n";
    cout << "2. See movies\n";
    cout << "3. See series\n";
    cout << "4. See reviews\n";
    cout << "5. Add movie\n";
    cout << "6. Add series\n";
    cout << "7. Add critic\n";
    cout << "8. Add review for critic\n";
    cout << "9. Flush database\n";
    cout << "10. Exit\n";
}
