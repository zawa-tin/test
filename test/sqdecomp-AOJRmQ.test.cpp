#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../src/dataStructure/sqdecomp.hpp"
#include "../src/utility/monoid/min_monoid.hpp"

#include <iostream>
#include <vector>

int main() {
	int n, q; std::cin >> n >> q;
	std::vector as(n, (int)((1LL << 31) - 1));
	zawa::sqdecomp<zawa::min_monoid<int>> sq(as);
	for (int _ = 0 ; _ < q ; _++) {
		int com, x, y; std::cin >> com >> x >> y;
		if (com == 0) {
			as[x] = y;
			sq.update(x, as[x]);
		}
		if (com == 1) {
			std::cout << sq.prod(x, y + 1) << std::endl;
		}
	}
}
