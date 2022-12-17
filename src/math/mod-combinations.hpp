#pragma once

#include <vector>

namespace zawa {

template <long long mod>
class mod_conbinations {
private:
    std::vector<long long> facs, inv_facs;

public:
    mod_conbinations(std::size_t n) : facs(2 * n + 1, 1LL), inv_facs(2 * n + 1) {
        for (std::size_t i = 0 ; i + 1 < facs.size() ; i++) {
            facs[i + 1] = facs[i] * (i + 1);
            facs[i + 1] %= mod;
        }
        long long base = facs.back();
        long long inv = 1LL;
        long long p = mod - 2;
        while (p > 0) {
            if (p & 1) {
                inv *= base;
                inv %= mod;
            }
            base = (base * base) % mod;
            p >>= 1;
        }
        inv_facs.back() = inv;
        for (int i = (int)facs.size() - 1 ; i - 1 >= 0 ; i--) {
            inv_facs[i - 1] = inv_facs[i] * i;
            inv_facs[i - 1] %= mod;
        }
    }

    long long P(std::size_t n, std::size_t r) {
        if (r > n) {
            return 0LL;
        }
        return (facs[n] * inv_facs[(n - r)]) % mod;
    }

    long long C(std::size_t n, std::size_t r) {
        if (r > n) {
            return 0LL;
        }
        return (P(n, r) * inv_facs[r]) % mod;
    }

    long long H(std::size_t n, std::size_t r) {
        if (n == 0 and r == 0) {
            return 1LL;
        }
        if (r > n + r - 1) {
            return 0LL;
        }
        return C(n + r - 1, r);
    }
};

} // namespace zawa
