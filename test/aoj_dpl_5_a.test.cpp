#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A"
#include <iostream>

#include "../src/math/modint.hpp"

using mint = zawa::modint<1000000007>;

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << mint(k).pow(n).val() << std::endl;
}
