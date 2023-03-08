#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

#include "../src/geometryR2/segment.hpp"
#include "../src/geometryR2/relation.hpp"

#include <iostream>

int main() {
	using namespace geoR2;
	int q; std::cin >> q;
	for (int _ = 0 ; _ < q ; _++) {
		segment s1, s2;
		std::cin >> s1.e1 >> s1.e2 >> s2.e1 >> s2.e2;
		std::cout << isIntersect(s1, s2) << std::endl;
	}
}
