#pragma once

#include <vector>
#include "../math/modint.hpp"

namespace zawa {

    using mint = zawa::modint<1000000007>;
    
    template<typename T>
    mint ear_dp(std::vector<T> as, std::vector<T> bs) {
        std::vector dp(as.size() + 1, std::vector<mint>(bs.size() + 1));
        for (int i = 0 ; i < as.size() + 1 ; i++) dp[i][0] = 1;

        for (int i = 1 ; i < as.size() + 1 ; i++) {
            for (int j = 1 ; j < bs.size() + 1 ; j++) {
                dp[i][j] += dp[i - 1][j];
                if (as[i - 1] == bs[j - 1]) dp[i][j] += dp[i][j - 1];
            }
        }

        return dp.back().back();
    }

} // namespace zawa
