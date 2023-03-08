#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_b"
#define ERROR 0.000001

#include "../src/geometryR2/point.hpp"
#include "../src/geometryR2/base.hpp"

#include <iostream>
#include <iomanip>

int main() {
	using namespace geoR2;
	point p; std::cin >> p;
	int d; std::cin >> d;
	std::cout << std::fixed << std::setprecision(8);
	std::cout << p.rotated(toRadian(d)) << std::endl;
}
