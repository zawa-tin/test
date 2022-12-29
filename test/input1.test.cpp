#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/6/ITP1_6_A"

#include "../src/template/input.hpp"

using namespace zawa::input;

int main() {
    int n;
    in(n);
    std::vector as(n, 0);
    in(as);
    for (int i = n - 1 ; i >= 0 ; i--) {
        std::cout << as[i] << (i == 0 ? '\n' : ' ');
    }
}
