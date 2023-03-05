#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/utility/monoid/min_monoid.hpp"
#include "../src/dataStructure/dualSegmentTree.hpp"
#include "../src/graph/simple/bfs.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

int main() {
	// int N, M; std::cin >> N >> M;
	// std::vector G(N, std::vector(0, 0));
	// std::vector R(N, std::vector(0, 0));
	// for (int i = 0 ; i < N ; i++) {
	// 	std::string S; std::cin >> S;
	// 	for (int j = 0 ; j < M ; j++) {
	// 		if (S[j] == '1') {
	// 			G[i].push_back(i + j + 1);
	// 			R[i + j + 1].push_back(i);
	// 		}
	// 	}
	// }
	// const int sup = 1e7;
	// auto F = zawa::bfs(G, 0, sup);
	// auto B = zawa::bfs(R, N - 1, sup);
	// zawa::dualSegmentTree<zawa::min_monoid<int>> S(std::vector(N, sup));
	// for (int v = 0 ; v < N ; v++) {
	// 	for (auto x : G[v]) {
	// 		S.update(v + 1, x, F[v] + B[x] + 1);
	// 	}
	// }
	// for (int i = 1 ; i + 1 < N ; i++) {
	// 	std::cout << (S[i] == sup ? -1 : S[i])  << (i + 1 == N - 1 ? '\n' : ' ');
	// }

	std::cout << "Hello World" << std::endl;
}

/*
 * AtCoder Beginner Contest 291 - F Teleporter and Closed off
 * https://atcoder.jp/contests/abc291/submissions/39476692
 */
