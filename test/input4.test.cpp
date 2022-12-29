#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/9/INFO1/4/INFO1_04_A"

#include "../src/template/input.hpp"

using namespace zawa::input;

int main() {
    std::pair p(0, 0); in(p);
    std::cout << p.first + p.second << std::endl;
}
