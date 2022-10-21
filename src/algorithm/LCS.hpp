#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace zawa::impl {

template <class T>
std::vector<T> lcs(const std::vector<T>& a, const std::vector<T>& b) {
    std::vector dp(a.size() + 1, std::vector(b.size() + 1, 0));
    for (std::size_t i = 0 ; i < a.size() ; i++) {
        for (std::size_t j = 0 ; j < b.size() ; j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    std::vector<T> res;
    std::size_t i = a.size(), j = b.size();
    while (dp[i][j] > 0) {
        if (dp[i - 1][j] == dp[i][j]) {
            i--;
        }
        else if (dp[i][j - 1] == dp[i][j]) {
            j--;
        }
        else {
            i--;
            j--;
            res.emplace_back(a[i]);
        }
    }
    std::reverse(res.begin(), res.end());
    return res;
}

}

namespace zawa {

template <class T>
std::vector<T> lcs(const std::vector<T>& a, const std::vector<T>& b) {
    return impl::lcs(a, b);
}

std::string lcs(const std::string& a, const std::string& b) {
    std::vector<char> newa(a.begin(), a.end()), newb(b.begin(), b.end());
    std::vector<char> reschar = impl::lcs(newa, newb);
    return std::string(reschar.begin(), reschar.end());
}

} // namespace zawa
