#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include <iostream>
#include <cassert>
#include "../src/math/Mobius-Function.hpp"

int main() {
    // https://atcoder.jp/contests/abc206/submissions/34197189
    zawa::Mobius_Function mob(10);
    assert(mob.get(1) == 1);
    assert(mob.get(2) == -1);
    assert(mob.get(4) == mob.get(9) and mob.get(8) == mob.get(9) and mob.get(8) == 0);
    assert(mob.get(6) == 1);

    std::cout << "Hello World" << std::endl;
}
