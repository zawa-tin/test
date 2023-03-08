#pragma once

#include "./line.hpp"
#include "./point.hpp"

#include <cassert>

namespace geoR2 {

point projection(const point& p, const line& l) {
	assert(l.isValid());
	real coeff = dot(l.b - l.a, p - l.a) / vec2(l.b - l.a).squareDistance();
	return coeff * l.b + (static_cast<real>(1) - coeff) * l.a;
}

} // namespace geoR2
