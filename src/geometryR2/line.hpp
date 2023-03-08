#pragma once

#include "./point.hpp"

#include <cassert>

namespace geoR2 {

struct line {
	point a, b;

	line() : a(0, 0), b(0, 0) {}
	line(const point& _a, const point& _b) : a(_a), b(_b) {}

	inline bool isValid() const {
		return !equals(a, b);
	}

};

bool isOrthogonal(const line& l1, const line& l2) {
	assert(l1.isValid());
	assert(l2.isValid());
	return sgn(dot(l1.b - l1.a, l2.b - l2.a)) == 0;
}

bool isParallel(const line& l1, const line& l2) {
	assert(l1.isValid());
	assert(l2.isValid());
	return sgn(cross(l1.b - l1.a, l2.b - l2.a)) == 0;
}

} // namespace geo2d
