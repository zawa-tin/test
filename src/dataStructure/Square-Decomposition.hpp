#pragma once

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace zawa {

template <class T, T (*op)(T, T), T (*e)()>
class Square_Decomposition {

private:
    int square;
    int size;
    std::vector<T> data;
    std::vector<T> bucket;

    T update(int id) {
        T res = e();
        for (int i = id * square ; i < std::min((int)data.size(), (id + 1) * square) ; i++) {
            res = op(res, data[i]);
        }
        bucket[id] = res;
        return res;
    }

public:
    Square_Decomposition(int n)
        : square(std::sqrt(n + 1))
        , size((n + square - 1) / square)
        , data(n, e())
        , bucket(size, e()) {}

    Square_Decomposition(std::vector<T> as)
        : square(std::sqrt((int)as.size() + 1))
        , size(((int)as.size() + square - 1) / square)
        , data(as.begin(), as.end())
        , bucket(size, e()) {

        for (int i = 0 ; i < size ; i++) {
            update(i);
        }
    }

    T update(int pos, T value) {
        data[pos] = value;
        return update(pos / square);
    }

    T query(int l, int r) {
        T res = e(); 
        for (int i = 0 ; i < size ; i++) {
            int p = i * square, q = (i + 1) * square;
            if (q <= l and r <= p) {
                continue;
            }
            if (l <= p and q <= r) {
                res = op(res, bucket[i]);
            }
            else {
                for (int j = std::max(l, p) ; j < std::min(r, q) ; j++) {
                    res = op(res, data[j]);
                }
            }
        }
        return res;
    }

    void print_data() {
        for (size_t i = 0 ; i < data.size() ; i++) {
            std::cout << data[i] << (i == data.size() - 1 ? '\n' : ' ');
        }
    }

    void print_data(int l, int r) {
        for (int i = l ; i < r ; i++) {
            std::cout << data.at(i) << (i == r - 1 ? '\n' : ' ');
        }
    }
    
    void print_bucket() {
        for (auto buc : bucket) {
            std::cout << buc << ' ';
        }
        std::cout << std::endl;
    }
    
    void print_bucket(int id) {
        std::cout << bucket.at(id) << std::endl;
    }

};

} // namespace zawa
