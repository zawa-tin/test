#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0022"

#include "../src/algorithm/Kadane.hpp"
#include<iostream>

int main() {
    while (1) {
        int n; std::cin >> n;
        if (!n) break;
        std::vector<long long> as(n);
        for (auto& a : as) std::cin >> a;
        zawa::Kadane<long long> kadane(as, -1000000000000000LL);
        kadane.build();
        std::cout << kadane.get() << std::endl;
    }
}
