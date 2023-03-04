#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/graph/simple/bipartiteJudge.hpp"
#include "../src/graph/simple/connectedComponents.hpp"

#include <iostream>

int main() {
	// int N, M; std::cin >> N >> M;
	// std::vector A(M, 0), B(M, 0);
	// for (int i = 0 ; i < M ; i++) {
	// 	std::cin >> A[i] >> B[i];
	// 	A[i]--; B[i]--;
	// }
	// std::vector P(N + 1, 1LL);
	// for (int i = 0 ; i < N ; i++) {
	// 	P[i + 1] = P[i] << 1;
	// }
	// long long ans = 0;
	// for (int bit = 0 ; bit < (1 << N) ; bit++) {
	// 	bool ok = true;
	// 	std::vector R(N, false);
	// 	std::vector id(N, -1);
	// 	int cnt = 0;
	// 	for (int i = 0 ; i < N ; i++) {
	// 		if (bit & (1 << i)) {
	// 			R[i] = true;
	// 		}
	// 		else {
	// 			id[i] = cnt++;
	// 		}
	// 	}
	// 	for (int i = 0 ; i < M ; i++) {
	// 		ok &= !(R[A[i]] and R[B[i]]);
	// 	}
	// 	if (!ok) {
	// 		continue;
	// 	}
	// 	std::vector G(cnt, std::vector(0, 0));
	// 	for (int i = 0 ; i < M ; i++) {
	// 		if (!R[A[i]] and !R[B[i]]) {
	// 			G[id[A[i]]].push_back(id[B[i]]);
	// 			G[id[B[i]]].push_back(id[A[i]]);
	// 		}
	// 	}
	// 	if (zawa::bipartiteJudge(G).ok()) {
	// 		ans += P[zawa::connectedComponents(G).size()];
	// 	}
	// }
	// std::cout << ans << std::endl;

	std::cout << "Hello World" << std::endl;
}

/*
 * AtCoder Beginner Contest 199 - D RGB Coloring 2
 * https://atcoder.jp/contests/abc199/submissions/39401194
 */
