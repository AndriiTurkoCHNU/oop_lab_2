#ifndef LAB2_MOVIE_DATABASE_H
#define LAB2_MOVIE_DATABASE_H

#include <iostream>

using namespace std;


class Movie {
private:
    static int generalId;
    int id;
    string title;
    float rating;
    int releaseYear;
    string director;
    static int getId();
public:
    void getInfo();
    void updateRating(float newRating);
    Movie(string title, int releaseYear, string director);
    Movie(string title, float rating, int releaseYear, string director);
    ~Movie();
};

class User {
private:
    string username;
    string email;
    string password;
public:
    void getInfo();
    User(string username, string password);
    User(string username, string email, string password);
    ~User();
};

class DatabaseConnection {
private:
    string host;
public:
    bool connect(const string& username, const string& password);
    void changeHost(string newHost);
    DatabaseConnection(string host = "localhost");
    ~DatabaseConnection();

};


#endif //LAB2_MOVIE_DATABASE_H
