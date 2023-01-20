#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include "../src/dataStructure/accum2d.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N; std::cin >> N;
	std::vector A(1001, std::vector(1001, 0));
	for (int _ = 0 ; _ < N ; _++) {
		int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
		A[y1][x1]++;
		A[y1][x2]--;
		A[y2][x1]--;
		A[y2][x2]++;
	}
	zawa::accum2d S(A);
	int ans = 0;
	for (const auto& s : S) {
		ans = std::max(ans, *max_element(s.begin(), s.end()));
	}
	std::cout << ans << std::endl;
}
