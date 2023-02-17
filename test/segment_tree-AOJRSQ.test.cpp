#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../src/utility/monoid/add_monoid.hpp"
#include "../src/dataStructure/segment_tree.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::segment_tree<zawa::add_monoid<int>> seg(n);
	for (int _ = 0 ; _ < q ; _++) {
		int com; std::cin >> com;
		if (com == 0) {
			int i, x; std::cin >> i >> x;
			seg.action(i - 1, x);
		}
		if (com == 1) {
			int s, t; std::cin >> s >> t;
			std::cout << seg.prod(s - 1, t) << std::endl;
		}
	}
}
