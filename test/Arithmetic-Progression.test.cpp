#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/math/Arithmetic-Progression.hpp"

#include <iostream>
#include <cassert>

int main() {
    zawa::Arithmetic_Progression arh(1, 2);
    assert(arh.get(1) == 1);
    assert(arh.get(2) == 3);
    assert(arh.get(4) == 7);
    assert(arh.accumulate(1, 5) == 1 + 3 + 5 + 7 + 9);
    assert(arh.accumulate(2, 4) == 3 + 5 + 7);
    std::cout << "Hello World" << std::endl;
}
