#pragma once

#include <vector>
#include <utility>

namespace zawa {

class linear_sieve {
private:
	std::vector<int> divs;
	std::vector<int> primes;

public:
	linear_sieve() {}
	linear_sieve(std::size_t n) : divs(n + 1, 1) {
		for (std::size_t i = 2 ; i < n + 1 ; i++) {
			if (divs[i] == 1) {
				divs[i] = i;
				primes.push_back((int)i);
			}
			for (const auto& p : primes) {
				if (p * i > n or p > divs[i]) {
					break;
				}
				divs[p * i] = p;
			}
		}
	}

	std::vector<std::pair<int, int>> factorize(int x) {
		std::vector res(0, std::pair(0, 0));
		while (x > 1) {
			res.emplace_back(divs[x], 0);
			while (divs[x] == res.back().first) {
				x /= divs[x];
				res.back().second++;
			}
		}
		return res;
	}

	std::vector<int> divisor(int x) {
		std::vector res(1, 1);
		for (const auto& [p, q] : factorize(x)) {
			std::size_t now = res.size();
			for (std::size_t i = 0 ; i < now ; i++) {
				int mul = p;
				for (int _ = 0 ; _ < q ; _++) {
					res.emplace_back(res[i] * mul);
					mul *= p;
				}
			}
		}
		return res;
	}

	std::vector<int> enumprime() {
		return primes;
	}

	bool isprime(int x) {
		return (x != 0 and x != 1 and divs[x] == x);
	}

	int operator[](int x) {
		return divs[x];
	}
};

}
