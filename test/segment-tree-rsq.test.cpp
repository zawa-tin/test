#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../src/dataStructure/segment-tree.hpp"

#include <iostream>
#include <cassert>
#include <vector>

namespace monoid {

long long op(long long a, long long b) {
    return a + b;
}

long long e() {
    return 0LL;
}

} // namespace monoid

int main() {
    int n, q; std::cin >> n >> q;
    std::vector dat(n, 0LL);
    zawa::segment_tree<long long, monoid::op, monoid::e> seg1(n), seg2(dat);
    for (int _ = 0 ; _ < q ; _++) {
        int com, x, y; std::cin >> com >> x >> y;
        if (com == 0) {
            x--;
            dat[x] += y;
            seg1.set(x, dat[x]);
            seg2.apply(x, y);
        }
        if (com == 1) {
            x--;
            assert(seg1.query(x, y) == seg2.query(x, y));
            std::cout << seg1.query(x, y) << std::endl;
        }
    }
}
