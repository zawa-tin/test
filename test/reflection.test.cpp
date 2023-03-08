#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR 0.00000001

#include "../src/geometryR2/reflection.hpp"

#include <iostream>
#include <iomanip>

int main() {
	using namespace geoR2;
	line l; std::cin >> l.a >> l.b;
	int q; std::cin >> q;
	std::cout << std::fixed << std::setprecision(10);
	for (int _ = 0 ; _ < q ; _++) {
		point p; std::cin >> p;
		std::cout << reflection(p, l) << std::endl;
	}
}
