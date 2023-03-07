#pragma once

#include "./point.hpp"

#include <cassert>

namespace geo2d {

struct line {
	point a, b;
	line(const point& _a, const point& _b) : a(_a), b(_b) {
		assert(!equals(a, b));
	}
};

} // namespace geo2d
