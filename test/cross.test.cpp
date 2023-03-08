#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "../src/geometryR2/point.hpp"

#include <iostream>
#include <iomanip>

int main() {
	using namespace geoR2;
	point p0, p1; std::cin >> p0 >> p1;
	int q; std::cin >> q;
	for (int _ = 0 ; _ < q ; _++) {
		point p2; std::cin >> p2;
		real outer = cross(p1 - p0, p2 - p0);
		real inner = dot(p1 - p0, p2 - p0);
		if (sgn(outer) == 1) {
			std::cout << "COUNTER_CLOCKWISE" << std::endl;
		}
		else if (sgn(outer) == -1) {
			std::cout << "CLOCKWISE" << std::endl;
		}
		else if (sgn(inner) == -1) {
			std::cout << "ONLINE_BACK" << std::endl;
		}
		else if (point(p1 - p0).squareDistance() < point(p2 - p0).squareDistance()) {
			std::cout << "ONLINE_FRONT" << std::endl;
		}
		else {
			std::cout << "ON_SEGMENT" << std::endl;
		}
	}
}
