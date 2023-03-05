#pragma once

#include "./primeSieve.hpp"

#include <vector>
#include <algorithm>

namespace zawa {

template <typename T>
class gcdConvolution {
private: 
	primeSieve sieve;

public:
	gcdConvolution(std::size_t n) : sieve(n) {}
	
	std::vector<T> fastZetaTransform(const std::vector<T>& f) const {
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

	std::vector<T> fastMobiusTransform(const std::vector<T>& F) const {
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

	std::vector<T> convolution(const std::vector<T>& f, const std::vector<T>& g) const {
		std::vector<T> F = fastZetaTransform(f);
		std::vector<T> G = fastZetaTransform(g);
		std::vector<T> H(std::min(F.size(), G.size()));
		for (int i = 0 ; i < (int)(H.size()) ; i++) {
			H[i] = F[i] * G[i];
		}
		return fastMobiusTransform(H);
	}
};

}// namespace zawa
