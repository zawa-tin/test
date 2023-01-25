#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A"

#include "../src/template/makebuc.hpp"

#include <iostream>
#include <vector>

int main() {
	int n; std::cin >> n;
	std::vector A(n, 0);
	for (auto& a : A) {
		std::cin >> a;
	}
	auto buc = zawa::makebuc(A, 10001);
	std::vector res(0, 0);
	for (int i = 0 ; i < 10001 ; i++) {
		for (int _ = 0 ; _ < buc[i] ; _++) {
			res.push_back(i);
		}
	}
	for (int i = 0 ; i < n ; i++) {
		std::cout << res[i] << (i + 1 == n ? '\n' : ' ');
	}
}
