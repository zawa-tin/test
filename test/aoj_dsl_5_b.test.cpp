#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include <cassert>
#include <iostream>

#include "../src/dataStructure/Accum-2D.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector ps(1001, std::vector<int>(1001));
    std::vector x1s(n, 0), y1s(n, 0), x2s(n, 0), y2s(n, 0);
    zawa::Accum_2D<int> accum1(1001, 1001), accum2(1001, 1001, 0);
    for (int _ = 0 ; _ < n ; _++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        accum1.add(y1, x1, 1);
        accum2.set(y1, x1, accum2.get(y1, x1) + 1);
        ps[y1][x1]++;

        accum1.add(y1, x2, -1);
        accum2.set(y1, x2, accum2.get(y1, x2) - 1);
        ps[y1][x2]--;

        accum1.add(y2, x1, -1);
        accum2.set(y2, x1, accum2.get(y2, x1) - 1);
        ps[y2][x1]--;

        accum1.add(y2, x2, 1);
        accum2.set(y2, x2, accum2.get(y2, x2) + 1);
        ps[y2][x2]++;
    }

    zawa::Accum_2D<int> accum3(ps), accum4(ps, 0);
    accum1.build();
    accum2.build();
    accum3.build();
    accum4.build();
    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for (int i = 0 ; i <= 1001 ; i++) {
        for (int j = 0 ; j <= 1001 ; j++) {
            ans1 = std::max(ans1, accum1.query(0, 0, i, j));
            ans2 = std::max(ans2, accum2.query(0, 0, i, j));
            ans3 = std::max(ans3, accum3.query(0, 0, i, j));
            ans4 = std::max(ans4, accum4.query(0, 0, i, j));
        }
    }

    assert(ans1 == ans2 and ans2 == ans3 and ans3 == ans4);
    std::cout << ans1 << std::endl;
}
