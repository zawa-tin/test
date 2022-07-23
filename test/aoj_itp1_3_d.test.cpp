#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D"

#include "../src/math/divisor.hpp"
#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int ans = 0;
    for (auto div : zawa::divisor(c)) {
        ans += a <= div and div <= b;
    }
    std::cout << ans << std::endl;
}
