#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../src/utility/monoid/rangeAddMonoid.hpp"

struct oM {
	using valueType = long long;
	static constexpr valueType identity = -1001;
	static valueType operation(const valueType& a, const valueType& b) {
		return b;
	}
};

struct action {
	using valueMonoid = zawa::rangeAddMonoid<long long>;
	using operatorMonoid = oM;
	static valueMonoid::valueType mapping(const valueMonoid::valueType& a, const operatorMonoid::valueType& b) {
		return valueMonoid::valueType(a.size * b, a.size);
	}
};

#include "../src/dataStructure/lazySegmentTree.hpp"

#include <iostream>
#include <vector>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::lazySegmentTree<action> S(std::vector(n, action::valueMonoid::valueType(0LL, 1ULL)));
	for (int _ = 0 ; _ < q ; _++) {
		int type; std::cin >> type;
		if (type == 0) {
			int s, t, x; std::cin >> s >> t >> x;
			S.update(s, t + 1, x);
		}
		if (type == 1) {
			int s, t; std::cin >> s >> t;
			std::cout << S.prod(s, t + 1).value << std::endl;
		}
	}
}
