#pragma once

#include "./base.hpp"

#include <cmath>
#include <istream>
#include <ostream>

namespace geoR2 {

struct point {
	real x, y;
	
	point() : x(0), y(0) {}
	point(const real& _x, const real& _y) : x(_x), y(_y) {}

	friend std::ostream &operator <<(std::ostream& os, const point& p) {
		return os << p.x << ' ' << p.y;
	}
	friend std::istream &operator >>(std::istream& is, point& p) {
		is >> p.x >> p.y;
		return is;
	}
	
	point &operator +=(const point& p) {
		x += p.x; y += p.y;
		return *this;
	}
	point &operator -=(const point& p) {
		x -= p.x; y -= p.y;
		return *this;
	}
	point &operator *=(const real& k) {
		x *= k; y *= k;
		return *this;
	}
	point &operator /=(const real& k) {
		x /= k; y /= k;
		return *this;
	}

	point operator +(const point& p) const {
		return point(*this) += p;	
	}
	point operator -(const point& p) const {
		return point(*this) -= p;
	}
	point operator *(const real& k) const {
		return point(*this) *= k;
	}
	friend point operator *(const real& r, const point& p) {
		return point(p) *= r;
	}
	point operator /(const real& k) const {
		return point(*this) /= k;
	}
	point operator +() const {
		return point(*this);
	}
	point operator -() const {
		return point(-x, -y);
	}

	real squareDistance() const {
		return x * x + y * y;
	}

	real distance() const {
		return sqrtl(x * x + y + y);
	}

	point rotated(const real& theta) const {
		return point(x * cosl(theta) - y * sinl(theta), x * sinl(theta) + y * cosl(theta));
	}
};

real dot(const point& a, const point& b) {
	return a.x * b.x + a.y * b.y;
}

bool equals(const point& a, const point& b) {
	return equals(a.x, b.x) and equals(a.y, b.y);
}

using vec2 = point;

} // namespace geoR2
