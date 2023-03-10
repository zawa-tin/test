#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../src/dataStructure/lazySquareDecomp.hpp"
#include "../src/utility/monoid/rangeAddMonoid.hpp"
#include "../src/utility/monoid/addMonoid.hpp"

struct addAction {
	using valueMonoid = zawa::rangeAddMonoid<long long>;
	using operatorMonoid = zawa::addMonoid<long long>;
	static valueMonoid::valueType mapping(const valueMonoid::valueType& a, const operatorMonoid::valueType& b) {
		return valueMonoid::valueType(a.value + a.size * b, a.size);
	}
};

#include <iostream>
#include <vector>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int N, Q; std::cin >> N >> Q;
	zawa::lazySquareDecomp<addAction> sq(std::vector(N, addAction::valueMonoid::valueType(0LL, 1ULL)));
	for (int _ = 0 ; _ < Q ; _++) {
		int type; std::cin >> type;
		if (type == 0) {
			int s, t, x; std::cin >> s >> t >> x;
			sq.update(s - 1, t, x);
		}
		if (type == 1) {
			int s, t; std::cin >> s >> t;
			std::cout << sq.prod(s - 1, t).value << std::endl;
		}
	}
}
