#pragma once

#include <vector>

namespace zawa {

template <class T = long long>
class matrix {
private:
	std::vector<std::vector<T>> dat;

public:
	std::size_t r, c;

	matrix(const std::vector<T>& dat) : dat(dat), r(dat.size()), c(dat[0].size())  {}
	matrix(std::size_t r, std::size_t c) : dat(r, std::vector<T>(c)), r(r), c(c) {}
	matrix(const matrix<T>& mat) : dat(mat.r, std::vector<T>(mat.c)), r(mat.r), c(mat.c) {
		for (std::size_t i = 0 ; i < r ; i++) {
			for (std::size_t j = 0 ; j < c ; j++) {
				dat[i][j] = mat[i][j];
			}
		}	
	}

	std::vector<T>& operator[](std::size_t i) {
		return dat[i];
	}
	const std::vector<T>& operator[](std::size_t i) const {
		return dat[i];
	}

	matrix& operator+=(const matrix<T>& mat) {
		for (std::size_t i = 0 ; i < r ; i++) {
			for (std::size_t j = 0 ; j < c ; j++) {
				dat[i][j] += mat[i][j];
			}
		}
		return *this;
	}
	matrix operator+(const matrix<T>& mat) {
		return matrix(*this) += mat;
	}

	matrix& operator-=(const matrix<T>& mat) {
		for (std::size_t i = 0 ; i < r ; i++) {
			for (std::size_t j = 0 ; j < c ; j++) {
				dat[i][j] -= mat[i][j];
			}
		}
		return *this;
	}
	matrix& operator-(const matrix<T>& mat) {
		return matrix(*this) -= mat;	
	}

	matrix operator*(const matrix<T>& mat) {
		matrix res(r, mat.c);
		for (std::size_t i = 0 ; i < r ; i++) {
			for (std::size_t j = 0 ; j < mat.c ; j++) {
				for (std::size_t k = 0 ; k < r ; k++) {
					res[i][j] += dat[i][k] * mat[k][j];
				}
			}
		}
		return res;
	}
	matrix operator*=(const matrix<T>& mat) {
		return (*this) = (*this) * mat;
	}

	matrix pow(long long p);
};

template <class T>
matrix<T> id_mul(std::size_t n) {
	matrix<T> res(n, n);
	for (std::size_t i = 0 ; i < n ; i++) {
		res[i][i] = 1;
	}
	return res;
}

template <class T>
matrix<T> matrix<T>::pow(long long p) {
	matrix<T> res = id_mul<T>(this->r);
	matrix<T> base(*this);
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
