#include "../src/string/rollinghash.hpp"

#include <iostream>
#include <string>

int main() {
	int n, q; std::cin >> n >> q;
	std::string s; std::cin >> s;
	zawa::rollinghash<200010> roll;
	auto hs = roll.build(s);
	for (int _ = 0 ; _ < q ; _++) {
		int a, b, c, d; std::cin >> a >> b >> c >> d;
		a--;
		c--;
		if (roll.hash(hs, a, b) == roll.hash(hs, c, d)) {
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;
		}
	}
}
