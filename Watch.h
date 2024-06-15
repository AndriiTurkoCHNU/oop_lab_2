#ifndef LAB2_WATCH_H
#define LAB2_WATCH_H


#include "helpers.h"

class iWatch {
public:
    virtual void getInfo() = 0;
};

class Movie: public iWatch {
private:
    static MyInt generalId;
    MyInt id; // has-an id
    string title;
    float rating;
    int *releaseYear;
    string director;
    static MyInt getGenId();
public:
    void getInfo() override;
    void updateRating(float newRating);
    MyInt getId();
    Movie(string title, int releaseYear, string director);
    Movie(string title, float rating, int rYear, string director);

    Movie(const Movie &other);
    Movie(Movie &&other);

    ~Movie();

    static MyInt getCurrentGeneralId();
};

class Series: public iWatch {
private:
    string title;
    float rating;
    int releaseYear;
    int seasons;
    string production;
public:
    Series(string title, float rating, int releaseYear, int seasons, string production);

    void getInfo() override;
};


#endif //LAB2_WATCH_H
