#include "../src/utility/monoid/xorMonoid.hpp"
#include "../src/dataStructure/segmentTree.hpp"

#include <iostream>
#include <vector>

int main() {
	int N, Q; std::cin >> N >> Q;
	std::vector A(N, 0);
	for (auto& a : A) {
		std::cin >> a;
	}
	zawa::segmentTree<zawa::xorMonoid<int>> seg(A);
	for (int _ = 0 ; _ < Q ; _++) {
		int T, X, Y; std::cin >> T >> X >> Y;
		if (T == 1) {
			seg.update(X - 1, Y);
		}
		if (T == 2) {
			std::cout << seg.prod(X - 1, Y) << std::endl;
		}
	}
}
