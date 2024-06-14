#ifndef LAB2_MOVIE_DATABASE_H
#define LAB2_MOVIE_DATABASE_H

#include <iostream>

using namespace std;


class MyInt {
private:
    int value;
public:
    MyInt(int value = 0);
    MyInt(const MyInt &other);

    MyInt operator++(int);
    MyInt operator+(const MyInt &other) const;

    friend std::ostream& operator<<(std::ostream& os, const MyInt& obj);
    friend std::istream& operator>>(std::istream& is, MyInt& obj);
};

class Movie {
private:
    static MyInt generalId;
    MyInt id;
    string title;
    float rating;
    int *releaseYear;
    string director;
    static MyInt getId();
public:
    void getInfo();
    void updateRating(float newRating);
    Movie(string title, int releaseYear, string director);
    Movie(string title, float rating, int rYear, string director);

    Movie(const Movie &other);
    Movie(Movie &&other);

    ~Movie();

    static MyInt getCurrentGeneralId();
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

    User(const User &other);

    ~User();
};

class DatabaseConnection {
private:
    string host;
public:
    bool connect(const string& username, const string& password);
    void changeHost(string newHost);
    DatabaseConnection(string host="localhost");

    DatabaseConnection(const DatabaseConnection &other);

    ~DatabaseConnection();

    string getHost() const;
};


#endif //LAB2_MOVIE_DATABASE_H
