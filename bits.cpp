//
// Created by magom on 17.09.2019.
//

#include "bits.h"

int number(unsigned long long m) {
    int i = 0;
    while (m > 0) {
        i += m % 2;
        m = m / 2;
    }
    return i;
}

void to2(unsigned long long a, std::ostream &os, int *Count, bool flag) {
    if (a == 0)
        return;
    if (a % 2 == 1 && flag) {
        *Count += 1;
        flag = false;
    }
    to2(a / 2, os, Count, flag);
    std::cout << a % 2;
}

void Count0(unsigned long long a, std::ostream &os, int *Count, bool flag) {
    if (a == 0)
        return;
    Count0(a / 2, os, Count, flag);
    *Count+=1;
}

bit bit::operator&(const bit &other) const {
    bit temp;
    unsigned long long temp_a = a & other.Hight();
    unsigned int temp_b = b & other.Low();
    temp.Get(temp_a, temp_b);
    return temp;
}

bit bit::operator|(const bit &other) const {
    bit temp;
    unsigned long long temp_a = a | other.Hight();
    unsigned int temp_b = b | other.Low();
    temp.Get(temp_a, temp_b);
    return temp;
}

bit bit::operator^(const bit &other) const {
    bit temp;
    unsigned long long temp_a = a ^other.Hight();
    unsigned int temp_b = b ^other.Low();
    temp.Get(temp_a, temp_b);
    return temp;
}

bit bit::operator~() {
    bit other;
    other.a = ~a;
    other.b = ~b;
    return other;
}

void bit::ShiftLeft(int i) {
    int k = 0;
    while (k < i) {
        if (b >= (1u << 31u)) {
            a = a << 1;
            ++a;
            b = b << 1;
            ++k;
        } else {
            a = a << 1;
            b = b << 1;
            ++k;
        }
    }
}

void bit::ShiftRight(int i) {
    unsigned int k = 0, f = (1u << 31u);
    while (k < i) {
        if (a % 2 == 1) {
            a = a >> 1;
            b = b >> 1;
            b = b | f;
            ++k;
        } else {
            a = a >> 1;
            b = b >> 1;
            ++k;
        }
    }
}

void bit::Get(unsigned long long i, unsigned int j) {
    a = i;
    b = j;
}

unsigned long long bit::Hight() const {
    return a;
}

unsigned int bit::Low() const {
    return b;
}

int bit::CountOfUnits() const {
    return number(a) + number(b);

}

int bit::operator==(const bit &other) const {
    int i1 = number(a) + number(b);
    int i2 = other.CountOfUnits();
    if (i1 == i2)
        return 1;
    else
        return 0;
}

int bit::operator<=(const bit &other) const {
    int i1 = number(a) + number(b);
    int i2 = other.CountOfUnits();
    if (i1 <= i2)
        return 1;
    else
        return 0;
}

int bit::operator>=(const bit &other) const {
    int i1 = number(a) + number(b);
    int i2 = other.CountOfUnits();
    if (i1 >= i2)
        return 1;
    else
        return 0;
}

int bit::operator<(const bit &other) const {
    int i1 = number(a) + number(b);
    int i2 = other.CountOfUnits();
    if (i1 < i2)
        return 1;
    else
        return 0;
}

int bit::operator>(const bit &other) const {
    int i1 = number(a) + number(b);
    int i2 = other.CountOfUnits();
    if (i1 > i2)
        return 1;
    else
        return 0;
}

int bit::Inclusion(const bit &other) const {
    if ((a & other.a) == a && (b & other.b) == b)
        return 1;
    else
        return 0;
}

bit::bit() {
    a = 0;
    b = 0;
}

std::ostream &operator<<(std::ostream &os, const bit &other) {
    bool flag = true;
    int aCount = 0, bCount = 0;
    os << other.a << " " << other.b << std::endl;
    Count0(other.a, os, &aCount, flag);
    for (int i = 0; i < 64 - aCount; ++i) {
        os << 0;
    }
    to2(other.a, os, &aCount, flag);
    os << " ";
    flag = true;
    Count0(other.b, os, &bCount, flag);
    for (int i = 0; i < 32 - bCount; ++i) {
        os << 0;
    }
    to2(other.b, os, &bCount, flag);
    os << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, bit &other) {
    std::string s;
    is >> s;
    int n = s.size();
    std::string t(n, '0');
    std::vector<int> v;
    while (s != t) {
        int d = 0;
        for (int i = 0; i < s.size(); i++) {
            d *= 10;
            d += (s[i] - 48);
            s[i] = char(48 + d / 2);
            d %= 2;
        }
        v.push_back(d);
    }

    unsigned int b_step = 1;
    for (int i = 0; i < 32 && i < v.size(); i++) {
        other.b += v[i] * b_step;
        b_step *= 2;
    }
    unsigned long long a_step = 1;
    for (int i = 32; i < v.size(); i++) {
        other.a += v[i] * a_step;
        a_step *= 2;
    }
    return is;
}