#ifndef LAB2_WATCH_H
#define LAB2_WATCH_H

#include <iostream>
using namespace std;

class iWatch {
public:
    virtual void getInfo() = 0;
};

class Movie: public iWatch {
private:
    int id; // has-an id
    string title;
    float rating;
    int *releaseYear;
    string director;
public:
    void getInfo() override;
    void updateRating(float newRating);
    int getId() const;
    Movie(int id, string title, int releaseYear, string director);
    Movie(int id, string title, float rating, int rYear, string director);

    Movie(const Movie &other);
    Movie(Movie &&other);

    ~Movie();

    string getTitle();
    float getRating() const;
    int getReleaseYear();
    string getDirector();
    static Movie createMovie();
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
    string getTitle();
    float getRating() const;
    int getReleaseYear() const;
    int getSeasons() const;
    string getProduction();

    static Series createSeries();
};


#endif //LAB2_WATCH_H
