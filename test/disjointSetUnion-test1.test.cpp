#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include "../src/dataStructure/disjointSetUnion.hpp"

#include <iostream>

int main() {
    int n, q; std::cin >> n >> q;
    zawa::disjointSetUnion uf(n);
    for (int _ = 0 ; _ < q ; _++) {
        int com, x, y; std::cin >> com >> x >> y;
        if (com == 0) uf.merge(x, y);
		else std::cout << uf.same(x, y) << std::endl;
    }
}
