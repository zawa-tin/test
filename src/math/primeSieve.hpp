#pragma once

#include <vector>

namespace zawa {

class primeSieve {
private:
	std::vector<bool> sieve;

public:
	primeSieve() {}
	primeSieve(std::size_t n) : sieve(n + 1, true) {
		if (n >= 0) {
			sieve[0] = false;
		}
		if (n >= 1) {
			sieve[1] = false;
		}
		for (std::size_t i = 2 ; i <= n ; i++) {
			if (sieve[i]) {
				for (std::size_t j = i * 2 ; j <= n ; j += i) {
					sieve[j] = false;
				}
			}
		}
	}

	inline bool operator[](std::size_t i) const {
		return sieve[i];
	}

	inline std::size_t size() const {
		return sieve.size();
	}
};

}// namespace zawa
