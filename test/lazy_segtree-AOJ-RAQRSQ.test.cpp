#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../src/dataStructure/lazy_segtree.hpp"
#include "../src/utility/monoid/range_add_monoid.hpp"
#include "../src/utility/monoid/add_monoid.hpp"

struct add_action {
	using value_monoid = zawa::range_add_monoid<long long>;
	using operator_monoid = zawa::add_monoid<long long>;
	static value_monoid::value_type mapping(const value_monoid::value_type& a, const operator_monoid::value_type& b) {
		return value_monoid::value_type(a.value + a.size * b, a.size);
	}
};

#include <vector>
#include <iostream>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int N, Q; std::cin >> N >> Q;
	zawa::lazy_segtree<add_action> S(std::vector(N, add_action::value_monoid::value_type(0LL, 1ULL)));
	for (int _ = 0 ; _ < Q ; _++) {
		int type; std::cin >> type;
		if (type == 0) {
			int s, t, x; std::cin >> s >> t >> x;
			S.update(s - 1, t, x);
		}
		if (type == 1) {
			int s, t; std::cin >> s >> t;
			std::cout << S.prod(s - 1, t).value << std::endl;
		}
	}
}
