#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A"

#include <iostream>
#include "../src/dataStructure/Accum-1D.hpp"

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<int> customers(t + 1);
    for (int i = 0 ; i < n ; i++) {
        int l, r;
        std::cin >> l >> r;
        customers[l]++;
        customers[r]--;
    }

    zawa::Accum_1D<int> accum(customers);
    int ans = 0;
    for (int i = 1 ; i <= t + 1 ; i++) {
        ans = std::max(ans, accum.query(0, i));
    }
    std::cout << ans << std::endl;
}
