#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/math/mobiusFunction.hpp"

#include <iostream>
#include <cassert>

int main() {
	zawa::mobiusFunction mf(10);
	std::vector ans = { 1, -1, -1, 0, -1, 1, -1, 0, 0, 1 };
	for (int i = 0 ; i < 10 ; i++) {
		assert(ans[i] == mf[i + 1]);
	}
	std::cout << "Hello World" << std::endl;
}
