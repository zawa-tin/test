#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../src/utility/monoid/minMonoid.hpp"

struct oM {
	using valueType = int;
	static constexpr valueType identity = -1;
	static valueType operation(const valueType& a, const valueType& b) {
		return b;
	}
};

struct action {
	using valueMonoid = zawa::minMonoid<int>;
	using operatorMonoid = oM;
	static const valueMonoid::valueType mapping(const valueMonoid::valueType& a, const operatorMonoid::valueType& b) {
		return (valueMonoid::valueType)b;
	}
};

#include "../src/dataStructure/lazySegmentTree.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::lazySegmentTree<action> S(n);
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
