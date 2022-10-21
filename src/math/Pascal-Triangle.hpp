#pragma once

#include <vector>

namespace zawa {

template <class T>
class Pascal_Triangle {
private:
    std::vector<std::vector<T>> table;
public:
    Pascal_Triangle(int max_n, int max_r)
        : table(max_n + 1, std::vector<T>(max_r + 1)) {
        table[0][0] = 1;
        for (int i = 1 ; i <= max_n ; i++) {
            for (int j = 1 ; j <= max_r ; j++) {
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
            }
        }
    }

    T ncr(int n, int r) {
        return table.at(n).at(r);
    }
};

} // namespace zawa
