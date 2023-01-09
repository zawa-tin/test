#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include "../src/algorithm/count-inv.hpp"

#include <iostream>
#include <vector>

int main() {
	int n; std::cin >> n;
	std::vector as(n, 0);
	for (auto& a : as) {
		std::cin >> a;
	}
	std::cout << zawa::count_inv(as) << std::endl;
}
