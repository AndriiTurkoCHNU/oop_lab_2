#ifndef LAB2_HELPERS_H
#define LAB2_HELPERS_H

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

    int getValue() const;
};


#endif //LAB2_HELPERS_H
