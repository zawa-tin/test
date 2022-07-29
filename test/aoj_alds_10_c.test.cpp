#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C"

#include <iostream>
#include <string>
#include <cassert>

#include "../src/algorithm/LCS.hpp"

int main() {
    int n;
    std::cin >> n;
    for (int _ = 0 ; _ < n ; _++) {
        std::string s, t;
        std::cin >> s >> t;
        std::vector<char> vs(s.size()), vt(t.size());
        for (int i = 0 ; i < s.size() ; i++) vs[i] = s[i];
        for (int i = 0 ; i < t.size() ; i++) vt[i] = t[i];
        zawa::LCS<char> lcs(vs, vt);
        lcs.build();

        assert(lcs.get_size() == lcs.get().size());

        std::cout << lcs.get().size() << std::endl;
    }
}
