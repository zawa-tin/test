#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include <iostream>
#include "../src/math/GCD-Convolution.hpp"
#include "../src/math/modint.hpp"

using mint = zawa::modint<998244353>;

int main() {
    int n;
    std::cin >> n;
    std::vector<mint> as(n), bs(n);
    for (auto& a : as) {
        int t;
        std::cin >> t;
        a = mint(t);
    }
    for (auto& b : bs) {
        int t;
        std::cin >> t;
        b = mint(t);
    }

    zawa::GCD_Convolution<mint> conv(n);
    auto ans = conv.convolution(as, bs);
    for (int i = 0 ; i < (int)(ans.size()) ; i++) {
        std::cout << ans[i].val() << (i + 1 == (int)ans.size() ? '\n' : ' ');
    }
}
