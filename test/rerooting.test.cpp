#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include "../src/graph/rerooting.hpp"

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	int n; std::scanf("%d", &n);
	struct V {
		int fir, sec;
		V(int _fir = 0, int _sec = 0) : fir(_fir), sec(_sec) {}
	};	
	struct E {
		int w;
		E(int _w = 0) : w(_w) {}
	};
	zawa::rerooting<V, E> dp(V(), n);
	for (int i = 0 ; i < n - 1 ; i++) {
		int u, v, w; std::scanf("%d%d%d", &u, &v, &w);
		dp.addEdge(u, v, E(w));
	}
	auto merge = [&](V a, V b, int, int) -> V {
		std::vector<int> tmp{ a.fir, a.sec, b.fir, b.sec };
		std::sort(tmp.begin(), tmp.end(), std::greater<int>());	
		return V{ tmp[0], tmp[1] };
	};
	auto walk = [&](V v, E e, int, int) -> V {
		return V{ v.fir + e.w, 0 };
	};
	int ans = 0;
	for (auto v : dp.run(merge, walk)) {
		ans = std::max(ans, v.fir + v.sec);
	}
	std::printf("%d\n", ans);
}
