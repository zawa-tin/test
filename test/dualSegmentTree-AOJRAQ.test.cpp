#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../src/utility/monoid/addMonoid.hpp"
#include "../src/dataStructure/dualSegmentTree.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;	
	zawa::dualSegmentTree<zawa::addMonoid<int>> S(n);
	for (int _ = 0 ; _ < q ; _++) {
		int t; std::cin >> t;
		if (t == 0) {
			int s, t, x; std::cin >> s >> t >> x;
			s--;
			S.update(s, t, x);
		}
		else {
			int i; std::cin >> i;
			std::cout << S[i - 1] << std::endl;
		}
	}
}
