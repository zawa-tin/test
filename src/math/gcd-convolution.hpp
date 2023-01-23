#pragma once

#include "./prime-sieve.hpp"

#include <vector>
#include <algorithm>

namespace zawa {

template <typename T>
class gcd_convolution {
private: 
	prime_sieve sieve;

public:
	gcd_convolution(std::size_t n) : sieve(n) {}
	
	std::vector<T> fast_zeta_transform(const std::vector<T>& f) {
		std::vector<T> res(f.begin(), f.end());
		for (int i = 1 ; i <= (int)(f.size()) ; i++) {
			if (sieve[i]) {
				for (int j = (int)res.size() / i ; j >= 1 ; j--) {
					res[j - 1] += res[j * i - 1];
				}
			}
		}
		return res;
	}

	std::vector<T> fast_mobius_transform(const std::vector<T>& F) {
		std::vector<T> res(F.begin(), F.end());
		for (int i = 1 ; i <= (int)(F.size()) ; i++) {
			if (sieve[i]) {
				for (int j = 1 ; j * i <= (int)(F.size()) ; j++) {
					res[j - 1] -= res[j * i - 1];
				}
			}
		}
		return res;
	}

	std::vector<T> convolution(const std::vector<T>& f, const std::vector<T>& g) {
		std::vector<T> F = fast_zeta_transform(f);
		std::vector<T> G = fast_zeta_transform(g);
		std::vector<T> H(std::min(F.size(), G.size()));
		for (int i = 0 ; i < (int)(H.size()) ; i++) {
			H[i] = F[i] * G[i];
		}
		return fast_mobius_transform(H);
	}
};

}// namespace zawa
