#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_C"

#include "../src/template/input.hpp"
using namespace zawa::input;

#include "../src/template/output.hpp"
using namespace zawa::output;

#include <algorithm>

int main() {
    while (1) {
        int a, b; in(a, b);
        if (a == 0 and b == 0) {
            break;
        }
        out(std::min(a, b), std::max(a, b));
    }
}
