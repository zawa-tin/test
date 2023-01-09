#pragma once

#include <vector>

namespace zawa::impl {

long long modpow(__int128_t a, __int128_t b, long long mod) {
	long long res = 1LL;
	a %= mod;
	while (b) {
		if (b & 1) {
			res = ((__int128_t)res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

std::vector<long long> cond = { 2, 325, 9375, 28178, 450775, 978504, 1795265022 };

} // namespace zawa::impl

namespace zawa {

bool isprime(long long n) {
	if (n <= 1) {
		return false;
	}
	if (n == 2 or n == 3) {
		return true;
	}
	if (!(n & 1)) {
		return false;
	}
	long long s = 0LL, d = n - 1;
	while (d % 2 == 0) {
		s++;
		d >>= 1;
	}
	for (auto c : impl::cond) {
		if (c % n == 0) {
			return true;
		}
		long long x = impl::modpow(c, d, n);
		if (x != 1) {
			long long t = 0;
			for ( ; t < s ; t++) {
				if (x == n - 1) {
					break;
				}
				x = ((__int128_t)x * x) % n;
			}
			if (t == s) {
				return false;
			}
		}
	}
	return true;
}

} // namespace zawa
