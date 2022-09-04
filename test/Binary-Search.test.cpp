#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D"

#include "../src/algorithm/Binary-Search.hpp"
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> ws(n);
    for (auto& w : ws) std::cin >> w;

    constexpr int sup = 100000 * 10000 + 100;
    
    std::cout << zawa::binary_search(sup, 0, [&](int p) -> bool {
                int iter = 0, now = 0, used = 1; 
                while (iter < (int)ws.size()) {
                    if (used > k) return false;       
                    if (now + ws[iter] <= p) {
                        now += ws[iter++];
                    }
                    else {
                        now = 0;
                        used++;
                    }
                }

                return true;

            }) << std::endl;
}
