#include "../src/dataStructure/dualSegmentTree.hpp"
#include "../src/utility/monoid/maxMonoid.hpp"

#include <vector>
#include <iostream>
#include <algorithm>

using seg = zawa::dualSegmentTree<zawa::maxMonoid<long long>>;
const long long inf = zawa::maxMonoid<long long>::identity;

int main() {
	int W, N; std::cin >> W >> N;
	std::vector dp(W + 1, inf);
	dp[0] = 0LL;
	for (int _ = 0 ; _ < N ; _++) {
		int L, R, V; std::cin >> L >> R >> V;
		R++;
		seg S(W + 1);
		for (int i = 0 ; i + L <= W ; i++) {
			if (dp[i] != inf) {
				S.update(i + L, std::min(i + R, W + 1), dp[i] + V);
			}
		}
		for (int i = 0 ; i <= W ; i++) {
			dp[i] = std::max(dp[i], S[i]);
		}
	}
	std::cout << (dp[W] == inf ? -1LL : dp[W]) << std::endl;
}
