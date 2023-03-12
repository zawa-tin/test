#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A"

#include "../src/template/sorted.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace zawa::util;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N; std::cin >> N;
	std::vector vec(N, 0);
	for (int i = 0 ; i < N ; i++) std::cin >> vec[i];
	auto sv = sorted(vec);
	for (int i = 0 ; i < N ; i++) {
		std::cout << sv[i] << (i + 1 == N ? '\n' : ' ');
	}
}
