#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../src/utility/monoid/minMonoid.hpp"

using vM = zawa::minMonoid<int>;

struct oM {
	using valueType = int;
	static constexpr int identity = -1;
	static int operation(const int& a, const int& b) {
		return b;
	}
};

struct action {
	using valueMonoid = vM;
	using operatorMonoid = oM;
	static const int mapping(const int& a, const int& b) {
		return b;
	}
};

#include "../src/dataStructure/lazySquareDecomp.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::lazySquareDecomp<action> sq(n);
	for (int _ = 0 ; _ < q ; _++) {
		int type; std::cin >> type;
		if (type == 0) {
			int s, t, x; std::cin >> s >> t >> x;
			sq.update(s, t + 1, x);
		}
		if (type == 1) {
			int s, t; std::cin >> s >> t;
			std::cout << sq.prod(s, t + 1) << std::endl;
		}
	}
}
