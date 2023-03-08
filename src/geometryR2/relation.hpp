#pragma once

#include "./point.hpp"
#include "./line.hpp"
#include "./segment.hpp"
#include "./ccw.hpp"

namespace geoR2 {
namespace impl {

int _ccw(const vec2& a, const vec2& b) {
	CCW value = ccw(a, b);
	if (value == CCW::COUNTER_CLOCKWISE) {
		return 1;
	}
	else if (value == CCW::CLOCKWISE) {
		return -1;
	}
	else if (value == CCW::ON_SEGMENT) {
		return 0;
	}
	else if (value == CCW::ONLINE_BACK) {
		return 2;
	}
	else {
		return -2;
	}
}

} // namespace impl

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

bool isIntersect(const segment& s1, const segment& s2) {
	assert(s1.isValid());
	assert(s2.isValid());
	vec2 v1(s1.e2 - s1.e1), v2(s2.e2 - s2.e1);
	return 
		impl::_ccw(v1, s2.e1 - s1.e1) * impl::_ccw(v1, s2.e2 - s1.e1) <= 0 
		and
		impl::_ccw(v2, s1.e1 - s2.e1) * impl::_ccw(v2, s1.e2 - s2.e1) <= 0;
}

} // namespace geoR2
