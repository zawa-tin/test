#define PROBLEM "https://atcoder.jp/contests/abc222/tasks/abc222_f"

#include "../src/graph/rerooting.hpp"

#include <cstdio>
#include <algorithm>

int main() {
	int N; std::scanf("%d", &N);
	struct V {
		long long e;
		V(long long _e = 0LL) : e(_e) {}
	};
	struct E {
		long long c;
		E(long long _c = 0LL) : c(_c) {}
	};
	zawa::rerooting<V, E> dp(V(), N);
	for (int _ = 0 ; _ < N - 1 ; _++) {
		int A, B, C; std::scanf("%d%d%d", &A, &B, &C);
		dp.addEdge(A - 1, B - 1, E{ C });
	}
	int D[N];
	for (int i = 0 ; i < N ; i++) std::scanf("%d", D + i);
	auto merge = [&](V a, V b, int, int) -> V {
		return V{ std::max(a.e, b.e) };
	};
	auto walk = [&](V a, E w, int x, int) -> V {
		return V{ w.c + std::max(a.e, (long long)D[x]) };
	};
	for (auto ans : dp.run(merge, walk))
		std::printf("%lld\n", ans.e);
}
