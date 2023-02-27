#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

// struct v_data {
// 	long long zero, one, inv;
// 	constexpr v_data(long long _zero = 0LL, long long _one = 0LL, long long _inv = 0LL) : zero(_zero), one(_one), inv(_inv) {}
// };
// 
// struct v_m {
// 	using value_type = v_data;
// 	static constexpr value_type identity{};
// 	static value_type operation(const value_type& a, const value_type& b) {
// 		return value_type{
// 			a.zero + b.zero, 
// 			a.one + b.one,
// 			a.inv + b.inv + a.one * b.zero
// 		};
// 	}
// };
// 
// struct o_m {
// 	using value_type = bool;
// 	static constexpr value_type identity{};
// 	static value_type operation(const value_type& a, const value_type& b) {
// 		return (a and !b) or (!a and b);
// 	}
// };
// 
// struct action {
// 	using value_monoid = v_m;
// 	using operator_monoid = o_m;
// 	static v_data mapping(const v_data& a, const bool& b) {
// 		if (!b) {
// 			return a;
// 		}
// 		else {
// 			return v_data{
// 				a.one,
// 				a.zero,
// 				a.one * a.zero - a.inv
// 			};
// 		}
// 	}
// };


#include "../src/dataStructure/lazy_segtree.hpp"

#include <iostream>
#include <vector>

int main() {
	// std::cin.tie(nullptr);
	// std::ios::sync_with_stdio;
	// int n, q; std::cin >> n >> q;
	// std::vector<v_data> A(n);
	// for (int i = 0 ; i < n ; i++) {
	// 	int x; std::cin >> x;
	// 	if (x == 0) {
	// 		A[i] = v_data{ 1, 0, 0 };
	// 	}
	// 	else {
	// 		A[i] = v_data{ 0, 1, 0 };
	// 	}
	// }
	// zawa::lazy_segtree<action> S(A);
	// for (int _ = 0 ; _ < q ; _++) {
	// 	int t, l, r; std::cin >> t >> l >> r;
	// 	l--;
	// 	if (t == 1) {
	// 		S.update(l, r, true);
	// 	}
	// 	else {
	// 		std::cout << S.prod(l, r).inv << std::endl;
	// 	}
	// }
	std::cout << "Hello World" << std::endl;
}

/*
 * AtCoder Library Practice Contest -L Lazy Segment Tree
 * https://atcoder.jp/contests/practice2/submissions/39280259
 */
