#pragma once
#include <vector>

namespace zawa::impl {

long long modpow(__int128_t a, __int128_t n, __int128_t mod) {
    long long res = 1;
    a %= mod;
    while (n) {
        if (n & 1) {
            res = __int128_t(res) * a % mod;
        }
        n >>= 1;
        a = a * a % mod;
    }
    return res;
}

const std::vector<long long> small = { 2, 7, 61 };
const std::vector<long long> big = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

} // namespace zawa::impl

namespace zawa {

bool miller_isprime(long long n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (!(n & 1)) {
        return false;
    }
    long long d = n - 1;
    long long s = 0;
    while (!(d & 1)) {
        d >>= 1;
        s++;
    }
    for (long long a : (n < (1LL << 32) ? impl::small : impl::big)) {
        if (a == n) {
            return true;
        }
        if (impl::modpow(a, d, n) == 1) {
            continue;
        }
        bool ok = false;
        for (long long r = 0 ; r < s ; r++) {
            if (impl::modpow(a, d * (1LL << r), n) == n - 1) { // == -1
                ok = true;
                break;
            }
        }
        if (!ok) {
            return false;
        }
    }
    return true;
}

} // namespace zawa
