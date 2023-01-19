#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A"

#include "../src/template/accum1d.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, T; std::cin >> N >> T;
	std::vector A(T + 1, 0);
	for (int _ = 0 ; _ < N ; _++) {
		int l, r; std::cin >> l >> r;
		A[l]++;
		A[r]--;
	}
	zawa::accum1d<int> imos(A.begin(), A.end());
	std::cout << *std::max_element(imos.begin(), imos.end()) << std::endl;
}
