#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../src/utility/monoid/rangeAddMonoid.hpp"

using vM = zawa::rangeAddMonoid<long long>;

struct oM {
	using valueType = long long;
	static constexpr valueType identity = -1001;
	static valueType operation(const valueType& a, const valueType& b) {
		return b;
	}
};

struct action {
	using valueMonoid = vM;
	using operatorMonoid = oM;
	static vM::valueType mapping(const vM::valueType& a, const long long& b) {
		return vM::valueType(a.size * b, a.size);
	}
};

#include "../src/dataStructure/lazySquareDecomp.hpp"

#include <iostream>
#include <vector>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::lazySquareDecomp<action> sq(std::vector(n, vM::valueType(0LL, 1ULL)));
	for (int _ = 0 ; _ < q ; _++) {
		int type; std::cin >> type;
		if (type == 0) {
			int s, t, x; std::cin >> s >> t >> x;
			sq.update(s, t + 1, x);
		}
		if (type == 1) {
			int s, t; std::cin >> s >> t;
			std::cout << sq.prod(s, t + 1).value << std::endl;
		}
	}
}
