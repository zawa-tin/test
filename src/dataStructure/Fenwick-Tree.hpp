#pragma once

#include <vector>

namespace zawa {

template <class T>
class Fenwick_Tree {
private:
    std::vector<T> container;
    int size;
    int pow_two;

    inline int lsb(int x) {
        return x & -x;
    }

    T sum(int id) {
        T res = 0;
        for (int x = id ; x > 0 ; x -= lsb(x)) {
            res += container[x];
        }

        return res;
    }

public:
    Fenwick_Tree(int n)
        : container(n + 1, T())
        , size(n + 1)
        , pow_two(1 << (std::__lg(n) + 1)) {}

    void add(int id, T val) {
        for (int x = id + 1 ; x <= size ; x += lsb(x)) {
            container[x] += val;
        }
    }
    
    T query(int l, int r) {
        return sum(r) - sum(l); 
    }

    int lower_bound(T val) {
        int res = 0;
        for (int x = pow_two ; x > 0 ; x >>= 1) {
            if (res + x <= size and container[res + x] < val) {
                val -= container[res + x];
                res += x;
            }
        }

        return res;
    }

    T get(int id) {
        return container[id];
    }

};

}// namespace zawa
