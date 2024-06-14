#ifndef LAB2_MOVIE_DATABASE_H
#define LAB2_MOVIE_DATABASE_H

#include <iostream>
#include <vector>
#include <map>

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

    int getValue() const;
};

class Movie {
private:
    static MyInt generalId;
    MyInt id; // has-an id
    string title;
    float rating;
    int *releaseYear;
    string director;
    static MyInt getGenId();
public:
    void getInfo();
    void updateRating(float newRating);
    MyInt getId();
    Movie(string title, int releaseYear, string director);
    Movie(string title, float rating, int rYear, string director);

    Movie(const Movie &other);
    Movie(Movie &&other);

    ~Movie();

    static MyInt getCurrentGeneralId();
};

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

    ~User();

    User &operator=(const User &other);
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
};

class Database {
private:
    vector<Movie> movies; // has-a list of movies
public:
    Database();
    Database(const Database &other);
    ~Database();

    void addMovie(const Movie& movie);
    size_t countMovies();
};


#endif //LAB2_MOVIE_DATABASE_H
