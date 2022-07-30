#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/algorithm/Kadane.hpp"
#include <iostream>
#include <cassert>

int main() {
    std::vector<int> ins = {-5, -1, 6, 4, 9, -6, -6, -7};
    zawa::Kadane<int> kadane(ins, -100);
    kadane.build();
    
    int ans = 19;
    int left = 2, right = 5;
    assert(left == kadane.get_seg().first);
    assert(right == kadane.get_seg().second);
    assert(ans == kadane.get());

    std::cout << "Hello World" << std::endl;
}
