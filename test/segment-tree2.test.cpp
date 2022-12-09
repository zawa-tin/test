#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../src/dataStructure/segment-tree.hpp"

#include <iostream>
#include <algorithm>
#include <vector>

int op(int x, int y) {
    return std::min(x, y);
}

int e() {
    return (int)2e9;
}

int main() {
    int n, q; std::cin >> n >> q;
    std::vector as(n, 0);
    for (auto& a : as) {
        std::cin >> a;
    }
    zawa::segment_tree<int, op, e> seg(as);
    for (int _ = 0 ; _ < q ; _++) {
        int l, r; std::cin >> l >> r;
        std::cout << seg.query(l, r) << std::endl;
    }
}
