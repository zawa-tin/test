#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include <iostream>
#include "../src/math/Extend-GCD.hpp"

int main() {
    int a, b;
    std::cin >> a >> b;
    auto [x, y] = zawa::extend_gcd(a, b);
    std::cout << x << ' ' << y << std::endl;
}
