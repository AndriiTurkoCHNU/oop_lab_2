#include "movie_database.h"

int main() {
    User user1 = User("user1", "password");
    user1.getInfo();

    Movie movie1 = Movie("Titanic", 1997, "James Cameron");
    movie1.getInfo();
    movie1.updateRating(7.9);
    movie1.getInfo();

    cout << "Current generalId: " << Movie::getCurrentGeneralId() << endl;

    Movie movie2 = Movie("Kill Bill: Vol. 1", 8.2, 2003, "Quentin Tarantino");
    cout << "Create new movie" << endl;
    cout << "Current generalId: " << Movie::getCurrentGeneralId() << endl;


    DatabaseConnection msSql = DatabaseConnection();
    msSql.connect("db_user", "strongPassw0rd");
    msSql.changeHost("127.0.0.1");
    msSql.connect("db_user", "password");

    const DatabaseConnection postgreSql = DatabaseConnection("localhost");
//    postgreSql.connect(); // error!
    cout << "PostgreSql host: " << postgreSql.getHost() << endl;

    return 0;
}
