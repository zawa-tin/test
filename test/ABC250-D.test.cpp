#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/math/linearSieve.hpp"
#include "../src/template/binary-search.hpp"

#include <iostream>
#include <vector>
#include <functional>

int main() {
	// std::vector primes = zawa::linearSieve(1000000).enumPrime();
	// long long N; std::cin >> N;
	// std::size_t ans = 0;
	// for (std::size_t i = 0 ; i < primes.size() ; i++) {
	// 	auto f = [&](int p) -> bool {
	// 		long long v = 1LL;
	// 		for (int _ = 0 ; _ < 3 ; _++) {
	// 			if (v > N) {
	// 				return false;
	// 			}
	// 			v *= primes[p];
	// 		}
	// 		return v <= N / primes[i];
	// 	};
	// 	if (f(i) == false) {
	// 		break;
	// 	}
	// 	ans += zawa::binary_search((int)i, (int)primes.size() - 1, f) - i;
	// }
	// std::cout << ans << std::endl;
	
	std::cout << "Hello World" << std::endl;
}

/*
 * AtCoder Beginner Contest 250 - D 250-like Number
 * https://atcoder.jp/contests/abc250/submissions/39448263
 */
