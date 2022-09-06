#pragma once

#include <vector>
#include <algorithm>

namespace zawa {

template <class T>
class Compression {
private:
    std::vector<T> arr;

public:
    Compression(const std::vector<T>& in)
        : arr(in.begin(), in.end()) {
            std::sort(arr.begin(), arr.end());
            arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
    }

    int get(T x) {
        return std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    }
};
    
}// namespace zawa
