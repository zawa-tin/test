#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C"

#include "../src/algorithm/LCS.hpp"
#include <iostream>

int main() {
    int q; std::cin >> q;
    for (int _ = 0 ; _ < q ; _++) {
        std::string a, b; std::cin >> a >> b;
        std::cout << zawa::lcs(a, b).size() << std::endl;
    }
}

/*
 * EDPC-F LCS
 * https://atcoder.jp/contests/dp/submissions/35825710
 */
