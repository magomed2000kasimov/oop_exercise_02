#include <iostream>
#include "bits.h"

int operator "" _sr(const char *st, size_t siz) {
    std::string s(siz, 'a');
    for (int j = 0; j < siz; ++j) {
        s[j] = st[j];

    }
    unsigned long long a = 0;
    unsigned int b = 0;
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
        b += v[i] * b_step;
        b_step *= 2;
    }
    unsigned long long a_step = 1;
    for (int i = 32; i < v.size(); i++) {
        a += v[i] * a_step;
        a_step *= 2;
    }
    return a;
}

int operator "" _jr(const char *st, size_t siz) {
    std::string s(siz, 'a');
    for (int j = 0; j < siz; ++j) {
        s[j] = st[j];

    }
    unsigned long long a = 0;
    unsigned int b = 0;
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
        b += v[i] * b_step;
        b_step *= 2;
    }
    unsigned long long a_step = 1;
    for (int i = 32; i < v.size(); i++) {
        a += v[i] * a_step;
        a_step *= 2;
    }
    return b;

}

int main() {
    bit a;
    std::cin>>a;
    std::cout<<a;
    bit b;
    std::cin>>b;
    std::cout<<b;
    a.ShiftLeft(1);
    bit f = a & b;
    std::cout<<f;
    f = a|b;
    std::cout<<f;
    f = ~a;
    std::cout<<f;
    return 0;
}