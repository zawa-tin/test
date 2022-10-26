#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../src/dataStructure/Square-Decomposition.hpp"

namespace sqrtDecomp {

int op(int a, int b) {
    return std::min(a, b);
}

int e() {
    return (int)((1LL << 31) - 1);
}

}

using RmQ = zawa::Square_Decomposition<int, sqrtDecomp::op, sqrtDecomp::e>;

#include <iostream>

int main() {
    int n, q; std::cin >> n >> q;
    RmQ rmq(n);
    for (int _ = 0 ; _ < q ; _++) {
        int com, x, y; std::cin >> com >> x >> y;
        if (com == 0) {
            rmq.update(x, y);
        }
        if (com == 1) {
            std::cout << rmq.query(x, y + 1) << std::endl;
        }
    }
}
