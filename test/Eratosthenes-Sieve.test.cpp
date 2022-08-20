#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include <iostream>
#include "../src/math/Eratosthenes-Sieve.hpp"

const int size = 100000000;

int main() {
    zawa::Eratosthenes_Sieve siv(size);
    int n;
    std::cin >> n;
    int ans = 0;
    for (int _ = 0 ; _ < n ; _++) {
        int a;
        std::cin >> a;
        ans += siv.is_prime(a);
    }

    std::cout << ans << std::endl;
}
