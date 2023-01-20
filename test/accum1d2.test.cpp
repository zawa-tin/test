#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../src/template/accum1d.hpp"

#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);	
	int N, Q; std::cin >> N >> Q;
	std::vector A(N, 0LL);
	for (auto& a : A) {
		std::cin >> a;
	}
	zawa::accum1d S(A);
	for (int _ = 0 ; _ < Q ; _++) {
		int l, r; std::cin >> l >> r;
		std::cout << S.sum(l, r) << std::endl;
	}
}
