#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1595"

#include "../src/graph/rerooting.hpp"

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	int n; std::scanf("%d", &n);
	struct V {
		int fir;
		V(int _fir = 0) : fir(_fir) {}
	};	
	struct E {};
	zawa::rerooting<V, E> dp(V(), n);
	for (int i = 0 ; i < n - 1 ; i++) {
		int u, v; std::scanf("%d%d", &u, &v);
		dp.addEdge(u - 1, v - 1, E());
	}
	auto merge = [&](V a, V b, int, int) -> V {
		return V{ std::max(a.fir, b.fir) };
	};
	auto walk = [&](V v, E e, int, int) -> V {
		return V{ v.fir + 1 };
	};
	for (auto v : dp.run(merge, walk)) {
		std::printf("%d\n", 2 * n - 2 - v.fir);
	}
}
