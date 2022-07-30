#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_D"

#include <iostream>
#include "../src/algorithm/Cyclic-Permutation.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ws(n);
    for (auto& w : ws) std::cin >> w;
    int allmin = 1000000;
    for (auto w : ws) allmin = std::min(allmin, w);
    auto cycles = zawa::decomp_cyclic_permutation(ws);
    int ans = 0;

    for (auto cycle : cycles) {
        int inval = 0;
        int outval = 0;
        int inmin = 1000000;
        for (auto c : cycle) inmin = std::min(inmin, ws[c]);
        for (auto c : cycle) inval += ws[c];
        inval += inmin * (cycle.size() - 2);
        for (auto c : cycle) outval += ws[c];
        outval -= inmin;
        outval += allmin * (cycle.size() - 1);
        outval += 2 * (allmin + inmin);
        ans += std::min(outval, inval);
    }

    std::cout << ans << std::endl;
}
