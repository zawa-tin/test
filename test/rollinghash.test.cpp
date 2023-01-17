#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../src/string/rollinghash.hpp"

#include <iostream>
#include <string>

int main() {
	std::string t, p; std::cin >> t >> p;
	zawa::rollinghash<1000000> roll;
	auto h1 = roll.build(t), h2 = roll.build(p);
	for (std::size_t i = 0 ; i + p.size() <= t.size() ; i++) {
		if (roll.hash(h1, i, i + p.size()) == roll.hash(h2, 0, p.size())) {
			std::cout << i << std::endl;
		}
	}
}
