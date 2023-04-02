#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../src/dataStructure/disjointSetUnion.hpp"

#include <cstdio>

int main() {
    int N, Q;
	std::scanf("%d%d", &N, &Q);
    zawa::disjointSetUnion uf(N);
    for (int _ = 0 ; _ < Q ; _++) {
		int t, u, v;
		std::scanf("%d%d%d", &t, &u, &v);
        if (t == 0) uf.merge(u, v);
		else std::printf("%d\n", uf.same(u, v));
    }
}
