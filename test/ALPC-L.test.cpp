struct vData {
	long long zero, one, inv;
	constexpr vData(long long _zero = 0LL, long long _one = 0LL, long long _inv = 0LL) : zero(_zero), one(_one), inv(_inv) {}
};

struct vM {
	using valueType = vData;
	static constexpr vData identity{};
	static vData operation(const vData& a, const vData& b) {
		return vData{
			a.zero + b.zero, 
			a.one + b.one,
			a.inv + b.inv + a.one * b.zero
		};
	}
};

struct oM {
	using valueType = bool;
	static constexpr bool identity{};
	static bool operation(const bool& a, const bool& b) {
		return (a and !b) or (!a and b);
	}
};

struct action {
	using valueMonoid = vM;
	using operatorMonoid = oM;
	static vData mapping(const vData& a, const bool& b) {
		if (!b) {
			return a;
		}
		else {
			return vData{
				a.one,
				a.zero,
				a.one * a.zero - a.inv
			};
		}
	}
};

#include "../src/dataStructure/lazySegmentTree.hpp"

#include <iostream>
#include <vector>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int n, q; std::cin >> n >> q;
	std::vector<vData> A(n);
	for (int i = 0 ; i < n ; i++) {
		int x; std::cin >> x;
		if (x == 0) {
			A[i] = vData{ 1, 0, 0 };
		}
		else {
			A[i] = vData{ 0, 1, 0 };
		}
	}
	zawa::lazySegmentTree<action> S(A);
	for (int _ = 0 ; _ < q ; _++) {
		int t, l, r; std::cin >> t >> l >> r;
		l--;
		if (t == 1) {
			S.update(l, r, true);
		}
		else {
			std::cout << S.prod(l, r).inv << std::endl;
		}
	}
}
