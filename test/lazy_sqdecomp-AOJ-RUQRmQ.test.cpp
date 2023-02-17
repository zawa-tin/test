#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../src/utility/monoid/min_monoid.hpp"

struct o_m {
	using value_type = int;
	static constexpr value_type identity = -1;
	static value_type operation(const value_type& a, const value_type& b) {
		return b;
	}
};

struct action {
	using value_monoid = zawa::min_monoid<int>;
	using operator_monoid = o_m;
	static const value_monoid::value_type mapping(const value_monoid::value_type& a, const operator_monoid::value_type& b) {
		return (value_monoid::value_type)b;
	}
};

#include "../src/dataStructure/lazy_sqdecomp.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::lazy_sqdecomp<action> sq(n);
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
