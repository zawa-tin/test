#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../src/dataStructure/fenwick_tree.hpp"
#include "../src/utility/fenwick_tree/add.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::fenwick_tree<zawa::add_structure<int>> fen(n);
	for (int _ = 0 ; _ < q ; _++) {
		int com, x, y; std::cin >> com >> x >> y;
		if (com == 0) {
			fen.add(x - 1, y);
		}
		if (com == 1) {
			std::cout << fen.sum(x - 1, y) << std::endl;
		}
	}
}
