#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"

#include <iostream>
#include "../src/math/Euler-Function.hpp"

int main() {
    long long n;
    std::cin >> n;
    std::cout << zawa::euler_function(n) << std::endl;
}
