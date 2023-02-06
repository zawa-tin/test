#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "../src/utility/monoid/min.hpp"
#include "../src/utility/monoid/add.hpp"

struct action {
	using value_monoid = zawa::min_monoid<long long>;
	using operator_monoid = zawa::add_monoid<long long>;
	static value_monoid::value_type mapping(const value_monoid::value_type& a, const operator_monoid::value_type& b) {
		return a + b;
	}
};

#include "../src/dataStructure/lazy_sqdecomp.hpp"

#include <iostream>
#include <vector>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::lazy_sqdecomp<action> sq(std::vector(n, (action::value_monoid::value_type)0));
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
