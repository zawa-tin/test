#pragma once

#include "./base.hpp"

#include <complex>
#include <cmath>
#include <istream>
#include <ostream>

namespace geo2d {

using point = std::complex<realType>;

point operator *(const point& a, const realType& k) {
	return point(a.real() * k, a.imag() * k);
}

std::istream &operator >>(std::istream& is, point& p) {
	realType x, y; is >> x >> y;
	p = point(x, y);
	return is;
}

std::ostream &operator <<(std::ostream& os, const point& p) {
	return os << p.real() << ' ' << p.imag();
}

point rotate(const point& p, const realType& theta) {
	return point(p.real() * cosl(theta) - p.imag() * sinl(theta), p.real() * sinl(theta) + p.imag() * cosl(theta));
}

inline realType dot(const point& a, const point& b) {
	return a.real() * b.real() + a.imag() * b.imag();
}

inline realType norm(const point& a) {
	return std::norm(a);
}

bool equals(const point& a, const point& b) {
	return equals(a.real(), b.real()) and equals(a.imag(), b.imag());
}

} // namespace geo2d
