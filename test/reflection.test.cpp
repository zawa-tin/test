#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR 0.00000001

#include "../src/geometry2d/reflection.hpp"

#include <iostream>
#include <iomanip>

int main() {
	using namespace geo2d;
	point p1, p2; std::cin >> p1 >> p2;
	const line l(p1, p2);
	int q; std::cin >> q;
	std::cout << std::fixed << std::setprecision(10);
	for (int _ = 0 ; _ < q ; _++) {
		point p; std::cin >> p;
		std::cout << reflection(p, l) << std::endl;
	}
}
