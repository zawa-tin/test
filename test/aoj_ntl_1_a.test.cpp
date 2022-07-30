#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
#include <iostream>

#include "../src/math/factorize.hpp"

int main() {
    int n; std::cin >> n;
    std::cout << n << ':';
    for (auto [x, cnt] : zawa::factorize(n)) {
        for (int i = 0 ; i < cnt ; i++) {
            std::cout << ' ' << x;
        }
    }
    std::cout << std::endl;
}
