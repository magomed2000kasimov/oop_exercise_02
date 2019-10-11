//
// Created by magom on 17.09.2019.
//

#ifndef OOP_EXERCISE_02_BITS_H
#define OOP_EXERCISE_02_BITS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class bit {
private:
    unsigned long long a;
    unsigned int b;
public:
    bit();

    bit(unsigned long long a1, unsigned int b1) {
        a = a1;
        b = b1;
    };

    void ShiftLeft(int i);

    void ShiftRight(int i);

    int Inclusion(const bit &other) const;

    void Get(unsigned long long i, unsigned int j);

    unsigned long long Hight() const;

    unsigned int Low() const;

    bit operator&(const bit &other) const;

    bit operator|(const bit &other) const;

    bit operator^(const bit &other) const;

    bit operator~() const;

    int operator<=(const bit &other) const;

    int operator>=(const bit &other) const;

    int operator==(const bit &other) const;

    int operator<(const bit &other) const;

    int operator>(const bit &other) const;

    friend std::ostream &operator<<(std::ostream &os, const bit &other);

    friend std::istream &operator>>(std::istream &is, bit &other);
};

bit operator "" _sr(const char *st, size_t siz);

#endif //OOP_EXERCISE_02_BITS_H
