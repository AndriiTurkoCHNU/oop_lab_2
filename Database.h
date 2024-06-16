#ifndef LAB2_DATABASE_H
#define LAB2_DATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Watch.h"
#include "User.h"
#include "Constants.h"

using namespace std;


class AbstractDatabase {
public:
    virtual void flushDB() = 0;
};


class Database: AbstractDatabase{
protected:
    vector<Movie> movies; // has-a list of movies
    vector<Series> series; // has-a list of series
    vector<Critic> critics; // has-a list of critics
public:
    Database();
    Database(const Database &other);
    virtual ~Database();

    void addMovie(Movie movie, bool fromFile=false);
    void addSeries(Series series, bool fromFile=false);
    void addCritic(Critic critic, bool fromFile=false);
    virtual size_t countMovies() final;
    size_t countSeries();
    size_t countCritics();

    // without overriding of pure virtual function from Abstract class, code compiles with errors
    void flushDB() override;
    static bool doubleCheck();

    void displayMovies();
    void displaySeries();
    void displayReviews();

    string getMovieById(const int& id);
    void addReviewForCritic();

    static Database readDBFromFile(const string& filename);
};


class DerivedDatabase final: public Database {
public:
    // cannot override final method
//    size_t countMovies() override;
};

// cannot inherit final class
//class MoreDerivedDatabase: DerivedDatabase {
//
//};


#endif //LAB2_DATABASE_H
