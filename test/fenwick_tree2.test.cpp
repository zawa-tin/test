#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../src/utility/fenwick_tree/add.hpp"
#include "../src/dataStructure/fenwick_tree.hpp"

#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N, Q; std::cin >> N >> Q;
	std::vector a(N, 0LL);
	for (auto& ai : a) {
		std::cin >> ai;
	}
	zawa::fenwick_tree<zawa::add_structure<long long>> fen(a);
	for (int _ = 0 ; _ < Q ; _++) {
		int t; std::cin >> t;
		if (t == 0) {
			int p, x; std::cin >> p >> x;
			fen.add(p, x);
		}
		if (t == 1) {
			int l, r; std::cin >> l >> r;
			std::cout << fen.sum(l, r) << std::endl;
		}
	}
}
