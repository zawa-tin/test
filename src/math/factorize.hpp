#pragma once

#include <vector>

namespace zawa {

    std::vector<std::pair<long long, int>> factorize(long long x) {
        std::vector<std::pair<long long, int>> res;

        for (long long i = 2 ; i * i <= x ; i++) {
            if (x % i) continue;
            int cnt = 0;
            while (!(x % i)) {
                cnt++;
                x /= i;
            }
            res.emplace_back(i, cnt);
        }
        if (x != 1) res.emplace_back(x, 1);

        return res;
    }

} // namespace zawa
