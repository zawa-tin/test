#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/dataStructure/segment-tree.hpp"

#include <iostream>
#include <vector>
#include <cassert>

int op(int a, int b) {
    return a ^ b;
}

int e() {
    return 0;
}

int main() {
    // int n, q; std::cin >> n >> q;
    // std::vector as(n, 0);
    // for (auto& a : as) {
    //     std::cin >> a;
    // }
    // zawa::segment_tree<int, op, e> seg1(as), seg2(as);
    // for (int _ = 0 ; _ < q ; _++) {
    //     int t, x, y; std::cin >> t >> x >> y;
    //     if (t == 1) {
    //         seg1.apply(x - 1, y);
    //         as[x - 1] ^= y;
    //         seg2.set(x - 1, as[x - 1]);
    //     }
    //     if (t == 2) {
    //         assert(seg1.query(x - 1, y) == seg2.query(x - 1, y));
    //         std::cout << seg1.query(x - 1, y) << std::endl;
    //     }
    // }

    std::cout << "Hello World" << std::endl;
}

/*
 * AtCoder Beginner Contest 185 - F Range Xor Query
 * https://atcoder.jp/contests/abc185/submissions/37110436
 */
