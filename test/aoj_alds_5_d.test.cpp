#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"

#include "../src/algorithm/Count-Inversion-Number.hpp"
#include <iostream>

int main() {
    int n; std::cin >> n;
    std::vector<int> as(n);
    for (auto& a : as) std::cin >> a;
    zawa::Count_Inversion_Number inv(as);
    inv.build();
    std::cout << inv.get() << std::endl;
}
