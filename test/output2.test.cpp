#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A"

#include "../src/template/input.hpp"
using namespace zawa::input;

#include "../src/template/output.hpp"
using namespace zawa::output;

int main() {
    int n; in(n);
    std::vector as(n, 0); in(as);
    std::vector buc(10001, 0);
    for (auto a : as) {
        buc[a]++;
    }
    std::vector bs(0, 0);
    for (int i = 0 ; i < 10001 ; i++) {
        for (int j = 0 ; j < buc[i] ; j++) {
            bs.push_back(i);
        }
    }
    out(bs);
}
