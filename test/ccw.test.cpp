#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "../src/geometryR2/point.hpp"
#include "../src/geometryR2/ccw.hpp"

#include <iostream>
#include <iomanip>

int main() {
	using namespace geoR2;
	point p0, p1; std::cin >> p0 >> p1;
	int q; std::cin >> q;
	for (int _ = 0 ; _ < q ; _++) {
		point p2; std::cin >> p2;
		auto value = ccw(p1 - p0, p2 - p0);
		if (value == CCW::COUNTER_CLOCKWISE) {
			std::cout << "COUNTER_CLOCKWISE" << std::endl;
		}
		else if (value == CCW::CLOCKWISE) {
			std::cout << "CLOCKWISE" << std::endl;
		}
		else if (value == CCW::ONLINE_BACK) {
			std::cout << "ONLINE_BACK" << std::endl;
		}
		else if (value == CCW::ONLINE_FRONT) {
			std::cout << "ONLINE_FRONT" << std::endl;
		}
		else {
			std::cout << "ON_SEGMENT" << std::endl;
		}
	}
}
