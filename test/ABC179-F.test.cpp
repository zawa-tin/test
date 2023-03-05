#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/utility/monoid/min_monoid.hpp"
#include "../src/dataStructure/dualSegmentTree.hpp"

#include <iostream>
#include <vector>

using seg = zawa::dualSegmentTree<zawa::min_monoid<int>>;

int main() {
	// int N, Q; std::cin >> N >> Q;
	// seg R(std::vector(N - 1, N - 1)), C(std::vector(N - 1, N - 1));
	// long long ans = (long long)(N - 2) * (N - 2);
	// for (int _ = 0 ; _ < Q ; _++) {
	// 	int T, X; std::cin >> T >> X;
	// 	X -= 2;
	// 	if (T == 1) {
	// 		ans -= C[X] - 1;
	// 		R.update(0, C[X], X + 1);
	// 	}
	// 	else {
	// 		ans -= R[X] - 1;
	// 		C.update(0, R[X], X + 1);
	// 	}
	// }
	// std::cout << ans << std::endl;

	std::cout << "Hello World\n";
}

/*
 * AtCoder Beginner Contest 179 - F Simplified Reversi
 * https://atcoder.jp/contests/abc179/submissions/39476714
 */
