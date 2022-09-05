#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>
#include "../src/dataStructure/Fenwick-Tree.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    zawa::Fenwick_Tree<int> fen(n);
    for (int _ = 0 ; _ < q ; _++) {
        int com, x, y;
        std::cin >> com >> x >> y;
        if (com == 0) {
            fen.add(x - 1, y);
        }
        else {
            std::cout << fen.query(x - 1, y) << std::endl;
        }
    }
}
