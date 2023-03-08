#pragma once

#include "./point.hpp"
#include "./line.hpp"
#include "./base.hpp"

namespace geoR2 {

enum class CCW {
	COUNTER_CLOCKWISE,
	CLOCKWISE,
	ONLINE_BACK,
	ONLINE_FRONT,
	ON_SEGMENT,
};

CCW ccw(const vec2 a, const vec2 b) {
	int outer = sgn(cross(a, b));
	if (outer == 1) {
		return CCW::COUNTER_CLOCKWISE;
	}
	else if (outer == -1) {
		return CCW::CLOCKWISE;
	}
	else if (sgn(dot(a, b)) == -1) {
		return CCW::ONLINE_BACK;
	}
	else if (a.squareDistance() < b.squareDistance()) {
		return CCW::ONLINE_FRONT;
	}
	else {
		return CCW::ON_SEGMENT;
	}
}

} // namespace geoR2
