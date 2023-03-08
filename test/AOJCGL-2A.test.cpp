#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"

#include "../src/geometryR2/line.hpp"
#include "../src/geometryR2/relation.hpp"

#include <iostream>

int main() {
	using namespace geoR2;
	int q; std::cin >> q;
	for (int _ = 0 ; _ < q ; _++) {
		line l1, l2;
		std::cin >> l1.a >> l1.b >> l2.a >> l2.b;
		if (isParallel(l1, l2)) {
			std::cout << 2 << std::endl;
		}
		else if (isOrthogonal(l1, l2)) {
			std::cout << 1 << std::endl;
		}
		else {
			std::cout << 0 << std::endl;
		}
	}
}
