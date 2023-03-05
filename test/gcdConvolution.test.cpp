#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../src/math/gcdConvolution.hpp"
#include "../src/math/modint.hpp"

#include <iostream>

using mint = zawa::modint<998244353>;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n; std::cin >> n;
    std::vector<mint> A(n), B(n);
    for (auto& a : A) {
        int t;  std::cin >> t;
        a = mint(t);
    }
    for (auto& b : B) {
        int t; std::cin >> t;
        b = mint(t);
    }
    zawa::gcdConvolution<mint> conv(n);
    auto ans = conv.convolution(A, B);
    for (int i = 0 ; i < (int)(ans.size()) ; i++) {
        std::cout << ans[i].val() << (i + 1 == (int)ans.size() ? '\n' : ' ');
    }
}
