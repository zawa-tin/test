#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR 0.00000001

#include "../src/geometryR2/projection.hpp"

#include <iostream>
#include <iomanip>

int main() {
	using namespace geoR2;
	point p1, p2; std::cin >> p1 >> p2;
	// std::cout << p1 << '\n' << p2 << std::endl;
	const line l(p1, p2);
	// std::cout << l.a << '\n' << l.b << std::endl;
	int q; std::cin >> q;
	std::cout << std::fixed << std::setprecision(10);
	for (int _ = 0 ; _ < q ; _++) {
		point p0; std::cin >> p0;
		std::cout << projection(p0, l) << std::endl;
	}
}
