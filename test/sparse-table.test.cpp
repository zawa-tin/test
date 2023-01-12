#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../src/dataStructure/sparse-table.hpp"
#include "../src/utility/sparse-table/min.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	std::vector<int> as(n, 0);
	for (auto& a : as) {
		std::cin >> a;
	}
	zawa::sparse_table<zawa::min_structure<int>> spt(as);
	for (int _ = 0 ; _ < q ; _++) {
		int l, r; std::cin >> l >> r;
		std::cout << spt.query(l, r) << std::endl;
	}
}
