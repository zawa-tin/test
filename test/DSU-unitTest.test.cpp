#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/dataStructure/DSU.hpp"

#include <iostream>
#include <cassert>

int main() {
    zawa::DSU uf(10);
    assert(uf.groups().size() == (std::size_t)10);
    assert(uf.leader(2) == 2); 
    uf.merge(1, 2);
    assert(uf.size(1) == 2);
    assert(uf.size(2) == 2);
    uf.merge(2, 3);
    assert(uf.size(1) == 3);
    assert(uf.size(2) == 3);
    assert(uf.size(3) == 3);
    assert(uf.groups().size() == (std::size_t)8);
    uf.merge(4, 5);
    uf.merge(2, 5);
    assert(uf.size(4) == 5);
    uf.merge(8, 9);
    /*
    for (auto group : uf.groups()) {
        for (auto x : group) {
            std::cout << x << ' ';
        }
        std::cout << std::endl;
    }
    0
    1 2 3 4 5
    6
    7
    8 9
    */
    std::cout << "Hello World" << std::endl;
}
