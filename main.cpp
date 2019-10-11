#include <iostream>
#include <sstream>
#include "bits.h"



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
    bit x = "1234"_sr;
    return 0;
}
