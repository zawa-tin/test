#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../src/algorithm/mo.hpp"

#include <cstdio>
#include <vector>
#include <utility>

int main() {
	int N, Q;
	std::scanf("%d%d", &N, &Q);
	std::vector<int> A(N);
	for (int i = 0 ; i < N ; i++)
		std::scanf("%d", &A[i]);
	std::vector<std::pair<int, int>> Query(Q);
	for (int i = 0 ; i < Q ; i++)
		std::scanf("%d%d", &Query[i].first, &Query[i].second);	
	std::vector<long long> Ans(Q);
	long long ans = 0LL;
	int nowl = 0, nowr = 0;
	for (auto [l, r, index] : zawa::mo(N, Query)) {
		while (nowr < r) ans += A[nowr++];
		while (nowl > l) ans += A[--nowl];
		while (nowr > r) ans -= A[--nowr];
		while (nowl < l) ans -= A[nowl++];
		Ans[index] = ans;
	}
	for (int i = 0 ; i < Q ; i++)
		std::printf("%lld\n", Ans[i]);
}
