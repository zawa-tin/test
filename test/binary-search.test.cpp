#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D"

#include "../src/template/binary-search.hpp"

#include <iostream>
#include <vector>
#include <functional>

int main() {
	int n, k; std::cin >> n >> k;
	std::vector ws(n, 0);
	for (auto& w : ws) {
		std::cin >> w;
	}
	auto f = [&](int p) -> bool {
		int iter = 0, now = 0, used = 1;
		while ((std::size_t)iter < ws.size()) {
			if (used > k) {
				return false;
			}
			if (now + ws[iter] <= p) {
				now += ws[iter++];
			}
			else {
				now = 0;
				used++;
			}
		}
		return true;
	};
	const int sup = 1e9 + 100;
	std::cout << zawa::binary_search(sup, 0, f) << std::endl;
}
