#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"

#include "../src/dataStructure/potentialized_unionfind.hpp"

#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    zawa::potentialized_unionfind<int> uf(n);
    for (int _ = 0 ; _ < q ; _++) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x, y, z;
            std::cin >> x >> y >> z;
            uf.merge(x, y, z);
        }
        if (t == 1) {
            int x, y;
            std::cin >> x >> y;
            if (uf.same(x, y)) {
                std::cout << uf.diff(y, x) << std::endl;
            }
            else {
                std::cout << '?' << std::endl;
            }
        }
    }
}
