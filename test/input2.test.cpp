#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/7/ITP1_7_D"

#include "../src/template/input.hpp"

using namespace zawa::input;

int main() {
    int n, m, l; 
    in(n, m, l);
    std::vector as(n, std::vector(m, 0));
    for (auto& a : as) {
        in(a);
    }
    std::vector bs(m, std::vector(l, 0));
    for (auto& b : bs) {
        in(b);
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < l ; j++) {
            long long val = 0;
            for (int k = 0 ; k < m ; k++) {
                val += as[i][k] * bs[k][j];
            }
            std::cout << val << (j + 1 == l ? '\n' : ' ');
        }
    }
}

