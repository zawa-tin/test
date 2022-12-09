#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../src/dataStructure/segment-tree.hpp"

#include <iostream>
#include <algorithm>
#include <cassert>

namespace monoid {

long long op(long long a, long long b) {
    return std::min(a, b);
}

long long e() {
    return (1LL << 31) - 1;
}

} // namespace monoid

int main() {
    int n, q; std::cin >> n >> q;
    zawa::segment_tree<long long, monoid::op, monoid::e> seg(n);
    for (int _ = 0 ; _ < q ; _++) {
        int com, x, y; std::cin >> com >> x >> y;
        if (com == 0) {
            seg.set(x, y);
        }
        if (com == 1) {
            y++;
            std::cout << seg.query(x, y) << std::endl;
        }
    }
}
