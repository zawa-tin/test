#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/math/primeSieve.hpp"
#include "../src/math/modint.hpp"
#include "../src/math/mod-combinations.hpp"

#include <iostream>
#include <vector>
#include <utility>
#include <map>

const long long mod = 998244353;
const int sup = 1000100;
using mint = zawa::modint<mod>;

int main() {
	// int n; std::cin >> n;
	// std::vector A(2 * n, 0);
	// for (auto& a : A) std::cin >> a;
	// std::map<int, int> mp;
	// for (auto& a : A) mp[a]++;
	// std::vector P(0, std::pair(0, 0));
	// for (const auto& [x, c] : mp) P.emplace_back(x, c);
	// std::vector S(P.size() + 1, 0);
	// for (int i = 0 ; i < (int)P.size() ; i++) S[i + 1] = S[i] + P[i].second;
	// zawa::primeSieve siv(sup);
	// zawa::mod_combinations<mod> mc(sup);
	// std::vector dp(n + 1, mint());
	// dp[0] = mint(1);
	// for (int i = 0 ; i < (int)P.size() ; i++) {
	// 	std::vector nxt(n + 1, mint());
	// 	for (int j = 0 ; j <= n and S[i] - j >= 0 ; j++) {
	// 		nxt[j] += dp[j] * mc.H(S[i] - j + 1, P[i].second);
	// 		if (siv[P[i].first] and j + 1 <= n) {
	// 			nxt[j + 1] += dp[j] * mc.H(S[i] - j + 1, P[i].second - 1);
	// 		}
	// 	}
	// 	dp = std::move(nxt);
	// }
	// std::cout << dp.back().val() << std::endl;

	std::cout << "Hello World" << std::endl;
}

/*
 * Codeforces Round 856(Div. 2) - D Counting Factorizations
 * https://codeforces.com/contest/1794/submission/196139941
 */
