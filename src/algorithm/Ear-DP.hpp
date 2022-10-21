#pragma once

#include <vector>
#include <string>

namespace zawa::impl {

template<typename T, typename RES>
RES ear_dp(const std::vector<T>& a, const std::vector<T>& b) {
    std::vector<std::vector<RES>> dp(a.size() + 1, std::vector<RES>(b.size() + 1));
    for (std::size_t i = 0 ; i < a.size() + 1 ; i++) {
        dp[i][0] = 1;
    }

    for (size_t i = 1 ; i < a.size() + 1 ; i++) {
        for (size_t j = 1 ; j < b.size() + 1 ; j++) {
            dp[i][j] += dp[i - 1][j];
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp.back().back();
}

} // namespace zawa::impl

namespace zawa {

template<typename T, typename RES>
RES ear_dp(const std::vector<T>& a, const std::vector<T>& b) {
    return impl::ear_dp<T, RES>(a, b);
}

template<typename RES>
RES ear_dp(const std::string& a, const std::string& b) {
    std::vector<char> newa(a.begin(), a.end()), newb(b.begin(), b.end());
    return impl::ear_dp<char, RES>(newa, newb);
}

}
