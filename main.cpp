#include "Database.h"
#include "User.h"

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


    // static method binding
    cout << "\n// static method binding" << endl;
    User u{"username", "password"};
    Critic c{"critic_name", "password", "-"};
    u.getInfo();
    c.getInfo();
    User *pu = new Critic{"critic-user", "psw", "Roger Joseph Ebert"};
    pu->getInfo();

    // run-time polymorphism with Base class pointer usage
    cout << "\n// run-time polymorphism | Base class pointer" << endl;
    User u2{"u2", "p"};
    Critic c2{"critic2_name", "p", "Name Surname 2"};
    u2.displayProfile();
    c2.displayProfile();
    User *pu2 = new Critic{"critic-user2", "psw", "Critic User 2"};
    pu2->displayProfile();

    // run-time polymorphism with Base class reference usage
    cout << "\n// run-time polymorphism | Base class reference" << endl;
    User u3{"u3", "p"};
    User &uRef = u3;
    uRef.displayProfile();

    Critic c3{"critic3_name", "p", "Name Surname 3"};
    User &cRef = c3;
    cRef.displayProfile();


    return 0;
}
