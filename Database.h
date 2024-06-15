#ifndef LAB2_DATABASE_H
#define LAB2_DATABASE_H

#include <iostream>
#include <vector>
#include <map>
#include "helpers.h"
#include "Watch.h"

using namespace std;


class AbstractDatabase {
public:
    virtual void flushDB() = 0;
};


class Database: AbstractDatabase{
protected:
    vector<Movie> movies; // has-a list of movies
public:
    Database();
    Database(const Database &other);
    virtual ~Database();

    void addMovie(const Movie& movie);
    virtual size_t countMovies() final;

    // without overriding of pure virtual function from Abstract class, code compiles with errors
    void flushDB() override;
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
