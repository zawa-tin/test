#define PROBLEM "https://atcoder.jp/contests/abc198/tasks/abc198_b"

#include "../src/template/reversed.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace zawa::util;

int main() {
	int N; std::cin >> N;	
	if (N == 0) {
		std::cout << "Yes" << std::endl;
		return 0;
	}
	std::vector vec(0, 0);
	std::string str;
	while (N % 10 == 0) N /= 10;
	while (N) {
		vec.push_back(N % 10);
		str.push_back((N % 10) + '0');
		N /= 10;
	}
	bool ok = (vec == reversed(vec)) and (str == reversed(str));
	std::cout << (ok ? "Yes" : "No") << std::endl;
}
