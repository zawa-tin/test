#pragma once

#include <vector>

namespace zawa {

class prime_sieve {
private:
	std::vector<bool> sieve;

public:
	prime_sieve() {}
	prime_sieve(std::size_t n) : sieve(n + 1, true) {
		if (n >= 0) {
			sieve[0] = false;
		}
		if (n >= 1) {
			sieve[1] = false;
		}
		for (std::size_t i = 2 ; i <= n ; i++) {
			if (sieve[i]) {
				for (std::size_t j = i * i ; j <= n ; j += i) {
					sieve[j] = false;
				}
			}
		}
	}
	bool operator[](std::size_t i) {
		return sieve[i];
	}
};

}// namespace zawa
