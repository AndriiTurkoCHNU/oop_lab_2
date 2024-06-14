#include "movie_database.h"

int main() {
    Database db;
    Movie movie1("Inception", 2010, "Christopher Nolan");
    Movie movie2("The Matrix", 1999, "The Wachowskis");
    Movie movie3("Interstellar", 8.6, 2014, "Christopher Nolan");

    db.addMovie(movie1);
    db.addMovie(movie2);
    db.addMovie(movie3);

    cout << "Movies in database: " << db.countMovies() << endl;
    movie1.getInfo();
    movie2.getInfo();
    movie3.getInfo();

    Critic critic1("john_doe", "password123", "John Doe");
    critic1.addReview(movie1.getId(), "Amazing movie!");
    critic1.addReview(movie2.getId(), "A revolutionary film!");

    cout << "Review for Inception: " << critic1.getReview(movie1.getId()) << endl;
    cout << "Review for The Matrix: " << critic1.getReview(movie2.getId()) << endl;

    return 0;

    return 0;
}
