#pragma once

#include <vector>
#include <algorithm>

namespace zawa {

    std::vector<long long> divisor(long long x) {
        std::vector<long long> res;

        for (long long i = 1 ; i * i <= x ; i++) {
            if (x % i) continue;
            res.emplace_back(i);
            if (i * i != x) res.emplace_back(x / i);
        }
        std::sort(res.begin(), res.end());

        return res;
    }

}// namespace zawa
