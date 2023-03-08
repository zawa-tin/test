#pragma once

#include "./point.hpp"

namespace geoR2 {

struct line {
	point a, b;
	line() : a(0, 0), b(0, 0) {}
	line(const point& _a, const point& _b) : a(_a), b(_b) {}
	bool isValid() const {
		return !equals(a, b);
	}
};

} // namespace geo2d
