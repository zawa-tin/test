#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../src/dataStructure/sparse-table.hpp"
 
#include <algorithm>
 
struct dat {
	using T = int;
	static T op(int a, int b) {
		return std::min(a, b);
	}
};

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	std::vector<int> as(n, 0);
	for (auto& a : as) {
		std::cin >> a;
	}
	zawa::sparse_table<dat> spt(as);
	for (int _ = 0 ; _ < q ; _++) {
		int l, r; std::cin >> l >> r;
		std::cout << spt.query(l, r) << std::endl;
	}
}
