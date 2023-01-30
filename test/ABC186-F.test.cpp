#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/dataStructure/fenwick_set.hpp"

#include <iostream>
// #include <vector>
// #include <algorithm>
#include <cassert>

int main() {
	// int H, W, M; std::cin >> H >> W >> M;
	// std::vector R(H, std::vector(1, W)), C(W, std::vector(1, H));
	// for (int _ = 0 ; _ < M ; _++) {
	// 	int Y, X; std::cin >> Y >> X;
	// 	Y--; X--;
	// 	R[Y].push_back(X);
	// 	C[X].push_back(Y);
	// }
	// for (auto& r : R) {
	// 	std::sort(r.begin(), r.end());
	// }
	// for (auto& c : C) {
	// 	std::sort(c.begin(), c.end());
	// }
	// long long ans = 0LL;
	// for (const auto& r : R) {
	// 	if (r[0] == 0) {
	// 		break;
	// 	}
	// 	ans += r[0];
	// }
	// for (const auto& c : C) {
	// 	if (c[0] == 0) {
	// 		break;
	// 	}
	// 	ans += c[0];
	// }
	// zawa::fenwick_set S(W + 1);
	// S.insert(W);
	// for (const auto& r : R) {
	// 	if (r.front() == 0) {
	// 		break;
	// 	}
	// 	int line = std::min(R[0][0], r[0]);
	// 	ans -= line - S.count(0, line);
	// 	for (const auto& v : r) {
	// 		S.insert(v);
	// 	}
	// }
	// std::cout << ans << std::endl;

	zawa::fenwick_set set(10);
	set.insert(2);
	set.insert(5);
	set.insert(7);
	set.insert(9);
	assert(set.kth_element(2) == 5);
	set.erase(2);
	assert(set.kth_element(2) == 7);
	std::cout << "Hello World" << std::endl;
}

/*
 * AtCoder Beginner Contest 186 - F Rook on Grid
 * https://atcoder.jp/contests/abc186/submissions/38472515
 */
