#define PROBLEM "https://atcoder.jp/contests/abc242/tasks/abc242_g"

#include "../src/algorithm/mo.hpp"

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	int N;
	std::scanf("%d", &N);
	int A[N];
	for (int i = 0 ; i < N ; i++)
		std::scanf("%d", A + i);
	int Q;
	std::scanf("%d", &Q);
	std::vector<std::pair<int, int>> Query(Q);
	for (auto& [l, r] : Query) {
		std::scanf("%d%d", &l, &r);
		--l;
	}
	int mx = *std::max_element(A, A + N) + 1;
	int S[mx];
	std::fill(S, S + mx, 0);
	int ans = 0;
	int Ans[Q];
	int L = 0, R = 0;
	for (const auto& [l, r, index] : zawa::mo(N, Query)) {
		while (R < r) {
			S[A[R]]++;
			if (!(S[A[R]] & 1)) ans++;
			R++;
		}
		while (L > l) {
			L--;
			S[A[L]]++;
			if (!(S[A[L]] & 1)) ans++;
		}
		while (R > r) {
			R--;
			S[A[R]]--;
			if (S[A[R]] & 1) ans--;
		}
		while (L < l) {
			S[A[L]]--;
			if (S[A[L]] & 1) ans--;
			L++;
		}
		Ans[index] = ans;
	}
	for (int i = 0 ; i < Q ; i++)
		std::printf("%d\n", Ans[i]);
}
