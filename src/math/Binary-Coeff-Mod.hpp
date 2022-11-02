#pragma once

#include <vector>

namespace zawa {

template <long long mod>
class Binary_Coeff {
private:
    std::vector<long long> factorial;
    std::vector<long long> inversion;
    std::vector<long long> inv_factorial;

public:
    Binary_Coeff(std::size_t size) 
        : factorial(size + 1, 1)
        , inversion(size + 1, 1)
        , inv_factorial(size + 1, 1) {
        for (int i = 1 ; i <= size ; i++) {
            factorial[i] = factorial[i - 1] * i % mod;
        }
        for (int i = 2 ; i <= size ; i++) {
            inversion[i] = (mod - mod / i) * inversion[mod % i] % mod;
        }
        for (int i = 1 ; i <= size ; i++) {
            inv_factorial[i] = inv_factorial[i - 1] * inversion[i] % mod;
        }
    }

    long long query(int n, int r, bool check = true) {
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
