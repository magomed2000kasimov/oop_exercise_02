#include <iostream>
#include <sstream>
#include "bits.h"

bit operator "" _sr(const char *st, size_t siz) {
    std::istringstream is(st);
    bit val;
    is >> val;
    return val;
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