#pragma once

#include "./projection.hpp"

namespace geo2d {

point reflection(const point& p, const line& l) {
	return -p + static_cast<realType>(2) * projection(p, l);
}

} // namespace geo2d
