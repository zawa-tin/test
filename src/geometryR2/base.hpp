#pragma once

#include <cmath>

namespace geoR2 {

using real = long double;

const real PI = acosl(-1);

inline real &eps() {
	static real EPS = 1e-14;
	return EPS;
}

inline void setEps(const real& EPS = 1e-14) {
	eps() = EPS;
}

inline int sgn(const real& value) {
	return (value < -eps() ? -1 : (value > +eps() ? 1 : 0));
}

inline bool equals(const real& a, const real& b) {
	return sgn(a - b) == 0;
}

inline real toRadian(const real& value) {
	return (value * PI) / 180;
}

} // namespace geoR2

namespace literals {

geoR2::real operator"" _rad(unsigned long long value) {
	return (static_cast<geoR2::real>(value) * geoR2::PI) / static_cast<geoR2::real>(180);
}

} // namespace literals

using namespace literals;
