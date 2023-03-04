#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/graph/Read-Graph.hpp"
#include "../src/graph/simple/connectedComponents.hpp"
#include "../src/graph/simple/bipartiteJudge.hpp"

#include <iostream>
#include <vector>

inline long long nC2(int value) {
	return (long long)value * (value - 1) / 2;
}

int main() {
	// int N, M; std::cin >> N >> M;
 //   	auto G = zawa::read_graph(N, M); 
	// auto colors = zawa::bipartiteJudge(G);
	// if (colors.ok()) {
	// 	auto groups = zawa::connectedComponents(G).comps();
	// 	long long ans = nC2(N) - M;
	// 	for (auto group : groups) {
	// 		int c1 = 0;
	// 		for (auto x : group) {
	// 			c1 += colors[x];
	// 		}
	// 		ans -= nC2(c1) + nC2(group.size() - c1);
	// 	}
	// 	std::cout << ans << std::endl;
	// }
	// else {
	// 	std::cout << 0 << std::endl;
	// }

	std::cout << "Hello World" << std::endl;
}

/*
 * AtCoder Beginner Contest 282 D- Make Bipartite 2
 * https://atcoder.jp/contests/abc282/submissions/39400340
 */


