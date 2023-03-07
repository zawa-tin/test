#pragma once

#include "./point.hpp"
#include "./line.hpp"

namespace geo2d {

point projection(const point& p, const line& l) {
	realType r = dot(l.b - l.a, p - l.a)  / norm(l.b - l.a);
	return r * l.b + (static_cast<realType>(1) - r) * l.a;
}

} // namespace geo2d
