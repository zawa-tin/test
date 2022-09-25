#pragma once

#include <vector>
#include <utility>
#include <string>

namespace zawa {

template <typename T>
std::vector<std::pair<T, int>> rle(const std::vector<T>& ins) {
    std::vector<std::pair<T, int>> res;
    for (size_t i = 0 ; i < ins.size() ; i++) {
        if (res.empty() or res.back().first != ins[i]) {
            res.emplace_back(ins[i], 1);
        }
        else {
            res.back().second++;
        }
    }
    return res;
}

std::vector<std::pair<char, int>> rle(const std::string& s) {
    std::vector<char> in(s.begin(), s.end());
    return rle(in);
}

} // namespace zawa
