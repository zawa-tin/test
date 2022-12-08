#pragma once

#include <vector>

namespace zawa {

template <long long mod>
class mod_inverses {
private:
    std::vector<long long> factorial;
    std::vector<long long> inversion;
    std::vector<long long> inv_factorial;

public:
    mod_inverses(std::size_t size) 
        : factorial(size + 1, 1)
        , inversion(size + 1, 1)
        , inv_factorial(size + 1, 1) {
        for (int i = 1 ; i <= (int)size ; i++) {
            factorial[i] = factorial[i - 1] * i % mod;
        }
        for (int i = 2 ; i <= (int)size ; i++) {
            inversion[i] = (mod - mod / i) * inversion[mod % i] % mod;
        }
        for (int i = 1 ; i <= (int)size ; i++) {
            inv_factorial[i] = inv_factorial[i - 1] * inversion[i] % mod;
        }
    }

    inline long long inv(int x) {
        return inversion[x];
    }

    inline long long inv_fac(int x) {
        return inv_factorial[x];
    }

    long long comb(int n, int r, bool check = true) {
        if (check) {
            if (n < 0 or n - r < 0 or r < 0) {
                return -1LL;
            }
            if (n >= (int)factorial.size() or r >= (int)factorial.size() or (n - r) >= (int)factorial.size()) {
                return -1LL;
            }
        }
        return (((factorial[n] * inv_factorial[n - r]) % mod) * inv_factorial[r]) % mod;
    }
};

} // namespace zawa
