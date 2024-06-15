#include "helpers.h"

MyInt::MyInt(int value)
        : value{value} {}

MyInt::MyInt(const MyInt &other)
        : value{other.value} {}

MyInt MyInt::operator++(int) {
    MyInt temp = *this;
    ++value;
    return temp;
}

MyInt MyInt::operator+(const MyInt &other) const {
    return {value + other.value};
}

std::ostream& operator<<(std::ostream& os, const MyInt& obj) {
    os << obj.value;
    return os;
}

std::istream& operator>>(std::istream& is, MyInt& obj) {
    is >> obj.value;
    return is;
}

int MyInt::getValue() const {
    return value;
}