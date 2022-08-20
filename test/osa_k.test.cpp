#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D"

#include <iostream>
#include "../src/math/osa_k.hpp"

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    zawa::osa_k osa(c);
    int ans = 0;
    for (auto d : osa.divisor(c)) {
        ans += (a <= d and d <= b);
    }

    std::cout << ans << std::endl;
}
