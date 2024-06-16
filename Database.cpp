#include "Database.h"


Database::Database() = default;

Database::Database(const Database &other)
    : movies{other.movies}, series{other.series}, critics{other.critics} {}

void Database::addMovie(Movie movie, bool fromFile) {
    for (const Movie& m : movies) {
        if (m.getId() == movie.getId()) {
            cout << "Movie with id " << movie.getId() << " already exists" << endl;
            return;
        }
    }

    this->movies.push_back(movie);

    if (!fromFile) {
        try {
            ofstream file(DATABASE_FILE, ios_base::app);
            if (file.is_open()) {
                file << "Movie," << movie.getId() << "," << movie.getTitle() << "," << movie.getRating() << ","
                     << movie.getReleaseYear() << "," << movie.getDirector() << "\n";
                file.close();
            } else {
                throw runtime_error("Unable to open file " + string(DATABASE_FILE));
            }
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
            return;
        }
    }
}


void Database::addSeries(Series s, bool fromFile) {
    this->series.push_back(s);

    if (!fromFile) {
        try {
            ofstream file(DATABASE_FILE, ios_base::app);
            if (file.is_open()) {
                file << "Series," << s.getTitle() << "," << s.getRating() << ","
                     << s.getReleaseYear() << "," << s.getSeasons() << "," << s.getProduction() << "\n";
                file.close();
            } else {
                throw runtime_error("Unable to open file " + string(DATABASE_FILE));
            }
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
            return;
        }
    }
}

void Database::addCritic(Critic critic, bool fromFile) {
    for (Critic c : critics) {
        if (c.getUsername() == critic.getUsername()) {
            cout << "Critic with username " << critic.getUsername() << " already exists" << endl;
            return;
        }
    }

    this->critics.push_back(critic);

    if (!fromFile) {
        try {
            ofstream file(DATABASE_FILE, ios_base::app);
            if (file.is_open()) {
                file << "Critic," << critic.getUsername() << "," << critic.getEmail() << "," << critic.getRealName()
                     << "\n";
                file.close();
            } else {
                throw runtime_error("Unable to open file " + string(DATABASE_FILE));
            }
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
            return;
        }
    }
}

size_t Database::countMovies() {
    return this->movies.size();
}

size_t Database::countSeries() {
    return series.size();
}

size_t Database::countCritics() {
    return critics.size();
}

Database::~Database() = default;

void Database::flushDB() {
    if (doubleCheck()) {
        movies.clear();
        series.clear();
        critics.clear();
        cout << "Database flushed." << endl;
    }
}

void Database::displayMovies() {
    cout << countMovies() << " movies in the database\n" << endl;

    for (Movie movie : movies) {
        movie.getInfo();
    }
}

void Database::displaySeries() {
    cout << countSeries() << " series in the database\n" << endl;

    for (Series s : series) {
        s.getInfo();
    }
}

void Database::displayReviews() {
    cout << countCritics() << " critics in the database\n" << endl;

    for (Critic critic : critics) {
        auto name = critic.getRealName();
        if (!name.empty())
            cout << "Reviews by critic " << name << ":" << endl;
        else
            cout << "Reviews by critic " << critic.getUsername() << ":" << endl;

        auto reviews = critic.getReviews();
        if (reviews.empty()) {
            cout << "No reviews\n";
        } else {
            for (const auto& review : reviews) {
                cout << "Movie \"" << getMovieById(review.first) << "\" review: " << review.second << endl;
            }
        }
        cout << endl;
    }
}

string Database::getMovieById(const int& id) {
    for (Movie movie : movies) {
        if (movie.getId() == id) {
            return movie.getTitle();
        }
    }
    return "Movie not found";
}

Database Database::readDBFromFile(const string &filename) {
    try {
        ifstream file(filename);
        Database db;

        if (!file.is_open()) {
            throw runtime_error("Could not open file " + filename);
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            vector<string> fields;
            string field;
            while (getline(iss, field, ',')) {
                fields.push_back(field);
            }

            if (fields[0] == "Movie") {
                int id = stoi(fields[1]);
                string title = fields[2];
                float rating = stof(fields[3]);
                int releaseYear = stoi(fields[4]);
                string director = fields[5];
                db.addMovie(Movie(id, title, rating, releaseYear, director), true);
            } else if (fields[0] == "Series") {
                string title = fields[1];
                float rating = stof(fields[2]);
                int releaseYear = stoi(fields[3]);
                int seasons = stoi(fields[4]);
                string production = fields[5];
                db.addSeries(Series(title, rating, releaseYear, seasons, production), true);
            } else if (fields[0] == "Critic") {
                string username = fields[1];
                string email = fields[2];
                string realName = fields[3];
                db.addCritic(Critic(username, email, realName), true);
            } else if (fields[0] == "Review") {
                string username = fields[1];
                int movieId = stoi(fields[2]);
                string review = fields[3];
                for (Critic& critic : db.critics) {
                    if (critic.getUsername() == username) {
                        critic.addReview(movieId, review);
                    }
                }
            }
        }

        file.close();

        return db;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return {};
    } catch (const exception& e) {
        cerr << "Error while reading database from file: " << e.what() << endl;
        return {};
    } catch (...) {
        cerr << "Unknown error while reading database from file" << endl;
        return {};
    }
}


void Database::addReviewForCritic() {
    string username;
    cout << "Enter critic username: ";
    cin >> username;

    for (Critic& critic : critics) {
        if (critic.getUsername() == username) {
            int movieId;
            cout << "Enter movie id: ";
            cin >> movieId;

            string review;
            cout << "Enter review: ";
            cin.ignore();
            getline(cin, review);

            critic.addReview(movieId, review);
            return;
        }
    }

    cout << "Critic not found" << endl;

}

bool Database::doubleCheck() {
    do {
        cout << "Do you really want to flush the database? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y') {
            return true;
        } else if (choice == 'n') {
            return false;
        } else {
            cout << "Invalid choice\n";
        }
    } while (true);
}
