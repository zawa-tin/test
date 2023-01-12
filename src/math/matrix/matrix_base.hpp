#pragma once

#include <vector>
#include <iostream>

namespace zawa {
	
template <class semiring>
class matrix {
private:
	using T = typename semiring::T;
	std::vector<std::vector<T>> dat;

public:
	matrix() = default;
	matrix(std::size_t h, std::size_t w) : dat(h, std::vector(w, semiring::e)) {}
	matrix(const std::vector<std::vector<T>>& dat) : dat(dat) {}
	matrix(const matrix& mat) : dat(mat.get()) {}

	const std::vector<T>& operator[](int i) const {
		return dat[i];
	}

	std::vector<T>& operator[](int i) {
		return dat[i];
	}

	matrix& operator+=(const matrix<semiring>& mat) {
		for (std::size_t i = 0 ; i < dat.size() ; i++) {
			for (std::size_t j = 0 ; j < dat[0].size() ; j++) {
				dat[i][j] = semiring::add(dat[i][j], mat[i][j]);
			}
		}
		return *this;
	}
	matrix operator+(const matrix<semiring>& mat) {
		return matrix(*this) += mat;
	}

	matrix& operator-=(const matrix<semiring>& mat) {
		for (std::size_t i = 0 ; i < dat.size() ; i++) {
			for (std::size_t j = 0 ; j < dat[0].size() ; j++) {
				dat[i][j] = semiring::add(dat[i][j], semiring::inv(mat[i][j]));
			}
		}
		return *this;
	}
	matrix& operator-(const matrix<semiring>& mat) {
		return matrix(*this) -= mat;
	}

	matrix operator*(const matrix<semiring>& mat) {
		matrix res(dat.size(), dat[0].size());
		for (std::size_t i = 0 ; i < dat.size() ; i++) {
			for (std::size_t j = 0 ; j < mat[0].size() ; j++) {
				for (std::size_t k = 0 ; k < dat[0].size() ; k++) {
					res[i][j] = semiring::add(res[i][j], semiring::mul(dat[i][k], mat[k][j]));
				}
			}
		}
		return res;
	}
	matrix& operator*=(const matrix<semiring>& mat) {
		matrix val = (*this) * mat;
		return *this = val;
	}

	std::vector<std::vector<T>> get() const {
		return dat;
	}
};

} // namespace zawa
 
namespace zawa::matrix_util {

template <class semiring>
static matrix<semiring> e;

} // namespace zawa::matrix_util

namespace zawa {

template <class semiring>
matrix<semiring> pow(matrix<semiring> base, long long p) {
	matrix<semiring> res = matrix_util::e<semiring>;
	while (p > 0) {
		if (p & 1) {
			res *= base;
		}
		base *= base;
		p >>= 1;
	}
	return res;
}

} // namespace zawa
