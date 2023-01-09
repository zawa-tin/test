#include "../src/math/miller-rabin.hpp"

#include <iostream>

int main() {
	int n; std::cin >> n;
	for (int _ = 0 ; _ < n ; _++) {
		long long a; std::cin >> a;
		std::cout << (zawa::isprime(a) ? "Yes" : "No") << std::endl;
	}
}

/* 
 * アルゴ式 ミラー-ラビンの素数判定法
 * https://algo-method.com/submissions/760056
 */
