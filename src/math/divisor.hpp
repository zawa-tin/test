#pragma once

#include <vector>
#include <algorithm>

namespace zawa {

    std::vector<int> divisor(int x) {
        std::vector<int> res;

        for (int i = 1 ; i*i <= x ; i++) {
            if (x % i) continue;
            res.emplace_back(i);
            if (i*i != x) res.emplace_back(x / i);
        }
        std::sort(res.begin(), res.end());

        return res;
    }

}
