#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../src/dataStructure/lazy_sqdecomp.hpp"

struct node {
	long long value;
	std::size_t size;
	constexpr node(long long value = 0LL, std::size_t size = 0ULL) : value(value), size(size) {}
};

struct value_add_monoid {
	using value_type = node;
	static constexpr value_type identity = node(0, 0);
	static value_type operation(const value_type& a, const value_type& b) {
		return node(a.value + b.value, a.size + b.size);
	}
};

struct action_add_monoid {
	using value_type = long long;
	static constexpr value_type identity{};
	static value_type operation(const value_type& a, const value_type& b) {
		return a + b;
	}
};

struct add_action {
	using value_monoid = value_add_monoid;
	using operator_monoid = action_add_monoid;
	static value_monoid::value_type mapping(const value_monoid::value_type& a, const operator_monoid::value_type& b) {
		return value_monoid::value_type(a.value + a.size * b, a.size);
	}
};

#include <iostream>
#include <vector>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int N, Q; std::cin >> N >> Q;
	zawa::lazy_sqdecomp<add_action> sq(std::vector(N, node(0LL, 1ULL)));
	for (int _ = 0 ; _ < Q ; _++) {
		int type; std::cin >> type;
		if (type == 0) {
			int s, t, x; std::cin >> s >> t >> x;
			// std::cout << "update " << s - 1 << ' ' << t << ' ' << x << ' ' << std::endl;
			sq.update(s - 1, t, x);
		}
		if (type == 1) {
			int s, t; std::cin >> s >> t;
			// std::cout << "prod " << s - 1 << ' ' << t << std::endl;
			std::cout << sq.prod(s - 1, t).value << std::endl;
		}
		// sq.debug();
	}
}
