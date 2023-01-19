#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../src/math/modint.hpp"
#include "../src/math/matrix.hpp"

#include <iostream>
#include <vector>

int main() {
	int N, M, K; std::cin >> N >> M >> K;
	zawa::matrix<zawa::modint<998244353>> A(N, M), B(M, K);
	for (int i = 0 ; i < N ; i++) {
		for (int j = 0 ; j < M ; j++) {
			int a; std::cin >> a;
			A[i][j] = a;
		}
	}
	for (int i = 0 ; i < M ; i++) {
		for (int j = 0 ; j < K ; j++) {
			int a; std::cin >> a;
			B[i][j] = a;
		}
	}
	auto C = A * B;
	for (int i = 0 ; i < N ; i++) {
		for (int j = 0 ; j < K ; j++) {
			std::cout << C[i][j].val() << (j + 1 == K ? '\n' : ' ');
		}
	}
}
