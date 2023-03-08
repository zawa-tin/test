#pragma once

#include "./ccw.hpp"
#include "./point.hpp"

namespace geoR2 {

struct segment {

	point e1, e2;

	segment() : e1(), e2() {}
	segment(const point& _e1, const point& _e2) : e1(_e1), e2(_e2) {}

	bool isValid() const {
		return !equals(e1, e2);
	}
};

} // namespace R2
