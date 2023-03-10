#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "../src/utility/monoid/minMonoid.hpp"
#include "../src/utility/monoid/addMonoid.hpp"

struct action {
	using valueMonoid = zawa::minMonoid<long long>;
	using operatorMonoid = zawa::addMonoid<long long>;
	static valueMonoid::valueType mapping(const valueMonoid::valueType& a, const operatorMonoid::valueType& b) {
		return a + b;
	}
};

#include "../src/dataStructure/lazySegmentTree.hpp"

#include <iostream>
#include <vector>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::lazySegmentTree<action> S(std::vector(n, 0LL));
	for (int _ = 0 ; _ < q ; _++) {
		int type; std::cin >> type;
		if (type == 0) {
			int s, t, x; std::cin >> s >> t >> x;
			S.update(s, t + 1, x);
		}
		if (type == 1) {
			int s, t; std::cin >> s >> t;
			std::cout << S.prod(s, t + 1) << std::endl;
		}
	}
}
