#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../src/query/Square-Decomposition.hpp"

namespace monoid {

int op(int a, int b) {
    return a + b;
}

int e() {
    return 0;
}

}

using RSQ = zawa::Sqrt_Decomposition<int, monoid::op, monoid::e>;

#include <iostream>

int main() {
    int n, q; std::cin >> n >> q;
    std::vector<int> as(n, 0);
    RSQ rsq(as);
    for (int _ = 0 ; _ < q ; _++) {
        int com, x, y; std::cin >> com >> x >> y;
        if (com == 0) {
            int nxt = as[x - 1] + y;
            as[x - 1] = nxt;
            rsq.update(x - 1, nxt);
        }
        if (com == 1) {
            std::cout << rsq.query(x - 1, y) << std::endl;
        }
    }
}
