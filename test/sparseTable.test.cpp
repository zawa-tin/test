#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../src/dataStructure/sparseTable.hpp"
#include "../src/utility/sparseTable/minStructure.hpp"

#include <iostream>

int main() {
	int N, Q; std::cin >> N >> Q;
	std::vector<int> A(N, 0);
	for (auto& a : A) {
		std::cin >> a;
	}
	zawa::sparseTable<zawa::minStructure<int>> S(A);
	for (int _ = 0 ; _ < Q ; _++) {
		int l, r; std::cin >> l >> r;
		std::cout << S.query(l, r) << std::endl;
	}
}
