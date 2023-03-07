#pragma once

#include <cmath>

namespace geo2d {

using realType = long double;

constexpr realType PI = acosl(-1);

inline realType &eps() {
	static realType EPS = 1e-14;
	return EPS;
}

inline void setEps(const realType& EPS = 1e-14) {
	eps() = EPS;
}

inline int sgn(const realType& value) {
	return (value < -eps() ? -1 : (value > +eps() ? 1 : 0));
}

inline bool equals(const realType& a, const realType& b) {
	return sgn(a - b) == 0;
}

inline realType toRadian(const realType& value) {
	return (value * PI) / static_cast<realType>(180);
}

} // namespace geo2d

namespace literals {

geo2d::realType operator"" _rad(unsigned long long value) {
	return (static_cast<geo2d::realType>(value) * geo2d::PI) / static_cast<geo2d::realType>(180);
}

} // namespace literals

using namespace literals;
