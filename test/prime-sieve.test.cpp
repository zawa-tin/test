#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include "../src/math/prime-sieve.hpp"

#include <iostream>

int main() {
	zawa::prime_sieve siv(100000000);
	int n; std::cin >> n;
	int ans = 0;
	for (int _ = 0 ; _ < n ; _++) {
		int v; std::cin >> v;
		ans += siv[v];
	}
	std::cout << ans << std::endl;
}
