#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include "../src/math/Miller-Rabin.hpp"

#include <iostream>
#include <cassert>

bool isprime(int x) {
    for (int i = 2 ; i * i <= x ; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return x != 1;
}

int main() {
    // https://algo-method.com/submissions/629135
    // これは10^18制約のverify
    int n;
    std::cin >> n;
    int ans = 0;
    for (int _ = 0 ; _ < n ; _++) {
        int k; 
        std::cin >> k;
        bool p = zawa::miller_isprime(k); 
        assert(p == isprime(k));
        ans += p;
    }
    std::cout << ans << std::endl;
}
