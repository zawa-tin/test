#pragma once

#include "./projection.hpp"

namespace geoR2 {

point reflection(const point& p, const line& l) {
	return -p + static_cast<real>(2) * projection(p, l);
}

} // namespace geoR2
