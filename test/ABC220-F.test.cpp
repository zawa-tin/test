#define PROBLEM "https://atcoder.jp/contests/abc220/tasks/abc220_f"

#include "../src/graph/rerooting.hpp"

#include <cstdio>

int main() {
	int N; std::scanf("%d", &N);
	struct V {
		long long s;
		int num;
		V(long long _s = 0LL, int _num = 0) : s(_s), num(_num) {}
	};
	struct E {};
	zawa::rerooting<V, E> dp(V(), N);
	for (int _ = 0 ; _ < N - 1 ; _++) {
		int u, v; std::scanf("%d%d", &u, &v);
		dp.addEdge(u - 1, v - 1, E());
	}
	auto merge = [&](V a, V b, int, int) -> V {
		return V{ a.s + b.s, a.num + b.num };
	};
	auto walk = [&](V a, E, int, int) -> V {
		return V{ a.s + a.num + 1, a.num + 1 };
	};
	for (auto ans : dp.run(merge, walk))
		std::printf("%lld\n", ans.s);
}
