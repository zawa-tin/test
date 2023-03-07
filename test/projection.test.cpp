#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR 0.00000001

#include "../src/geometry2d/projection.hpp"

#include <iostream>
#include <iomanip>

using namespace geo2d;

int main() {
	point p1, p2; std::cin >> p1 >> p2;
	const line l(p1, p2);
	int q; std::cin >> q;
	std::cout << std::fixed << std::setprecision(10);
	for (int _ = 0 ; _ < q ; _++) {
		point p0; std::cin >> p0;
		point ans = projection(p0, l);
		std::cout << ans.real() << ' ' << ans.imag() << std::endl;
	}
}
