#pragma once

#include "./prime-sieve.hpp"

#include <vector>

namespace zawa {

class mobius_function {
private:
	std::vector<int> table;

public:
	mobius_function() {}
	mobius_function(std::size_t n) : table(std::vector(n + 1, 1)) {
		prime_sieve siv(n);
		for (std::size_t i = 2 ; i <= n ; i++) {
			if (siv[i]) {
				for (std::size_t j = i ; j <= n ; j += i) {
					if (!(j % (i * i))) {
						table[j] = 0;
					}
					else {
						table[j] *= -1;
					}
				}
			}
		}
	}

	int operator[](int i) {
		return table[i];
	}
};

}// namespace zawa
