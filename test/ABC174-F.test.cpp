#define PROBLEM "https://atcoder.jp/contests/abc174/tasks/abc174_f"

#include "../src/algorithm/mo.hpp"

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	int N, Q;
	std::scanf("%d%d", &N, &Q);
	std::vector<int> C(N);
	for (int i = 0 ; i < N ; i++)
		std::scanf("%d", &C[i]);
	std::vector<std::pair<int, int>> Query(Q);
	for (auto& [l, r] : Query) {
		std::scanf("%d%d", &l, &r);
		l--;
	}
	int ans = 0;
	std::vector<int> Ans(Q);
	std::vector<int> State(*std::max_element(C.begin(), C.end()) + 1);
	int nowl = 0, nowr = 0;
	for (auto [l, r, index] : zawa::mo(N, Query)) {
		while (nowr < r) {
			if (State[C[nowr]] == 0) ans++;
			State[C[nowr]]++;
			nowr++;
		}	
		while (nowl > l) {
			nowl--;
			if (State[C[nowl]] == 0) ans++;
			State[C[nowl]]++;
		}
		while (nowr > r) {
			nowr--;
			State[C[nowr]]--;
			if (State[C[nowr]] == 0) ans--;
		}
		while (nowl < l) {
			State[C[nowl]]--;
			if (State[C[nowl]] == 0) ans--;
			nowl++;
		}
		Ans[index] = ans;
	}
	for (int i = 0 ; i < Q ; i++)
		std::printf("%d\n", Ans[i]);
}
