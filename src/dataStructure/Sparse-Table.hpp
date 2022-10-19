#pragma once
#include <vector>

namespace zawa {

template <class T, T (*op)(T, T)>
class Sparse_Table {
private:
    std::vector<std::vector<T>> table;

public:
    Sparse_Table(std::vector<T> as) 
        : table(std::__lg(as.size()) + 1, std::vector(as.size(), 0)) {
            
        for (std::size_t i = 0 ; i < as.size() ; i++) {
            table[0][i] = as[i];
        }

        for (std::size_t i = 1 ; i < table.size() ; i++) {
            std::size_t pt = (1 << i);
            for (std::size_t j = 0 ; j + pt - 1 < table[i].size() ; j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (pt >> 1)]);
            }
        }
    }

    T query(int l, int r) {
        int lg = std::__lg(r - l);
        return op(table[lg][l], table[lg][r - (1 << lg)]);
    }

    std::vector<std::vector<T>> hoge() {
        return table;
    }

};

} // namespace zawa
