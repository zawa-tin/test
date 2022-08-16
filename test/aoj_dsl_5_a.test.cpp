#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A"

#include <iostream>
#include <cassert>
#include "../src/dataStructure/Accum-1D.hpp"

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<int> ls(n), rs(n);
    for (int i = 0 ; i < n ; i++) std::cin >> ls[i] >> rs[i];

    zawa::Accum_1D<int> test1(t + 1), test2(t + 1, 0);
    std::vector<int> customers(t + 1);

    for (int i = 0 ; i < n ; i++) {
        test1.add(ls[i], 1);
        test1.add(rs[i], -1);

        test2.set(ls[i], test2.get(ls[i]) + 1);
        test2.set(rs[i], test2.get(rs[i]) - 1);

        customers[ls[i]]++;
        customers[rs[i]]--;
    }

    zawa::Accum_1D<int> test3(customers), test4(customers, 0);

    test1.build();
    test2.build();
    test3.build();
    test4.build();

    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for (int i = 0 ; i <= t + 1 ; i++) {
        ans1 = std::max(ans1, test1.query(0, i));
        ans2 = std::max(ans2, test2.query(0, i));
        ans3 = std::max(ans3, test3.query(0, i));
        ans4 = std::max(ans4, test4.query(0, i));
    }

    assert(ans1 == ans2 and ans2 == ans3 and ans3 == ans4);

    std::cout << ans1 << std::endl;
}
