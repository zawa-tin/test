#pragma once

#include "./primeSieve.hpp"

#include <vector>

namespace zawa {

class mobiusFunction {
private:
	std::vector<int> table;

public:
	mobiusFunction() {}
	mobiusFunction(std::size_t n) : table(std::vector(n + 1, 1)) {
		primeSieve siv(n);
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

	inline int operator[](int i) const {
		return table[i];
	}
};

}// namespace zawa
