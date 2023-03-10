#include "../src/utility/monoid/minMonoid.hpp"
#include "../src/dataStructure/dualSegmentTree.hpp"

#include <iostream>
#include <vector>

using seg = zawa::dualSegmentTree<zawa::minMonoid<int>>;

int main() {
	int N, Q; std::cin >> N >> Q;
	seg R(std::vector(N - 1, N - 1)), C(std::vector(N - 1, N - 1));
	long long ans = (long long)(N - 2) * (N - 2);
	for (int _ = 0 ; _ < Q ; _++) {
		int T, X; std::cin >> T >> X;
		X -= 2;
		if (T == 1) {
			ans -= C[X] - 1;
			R.update(0, C[X], X + 1);
		}
		else {
			ans -= R[X] - 1;
			C.update(0, R[X], X + 1);
		}
	}
	std::cout << ans << std::endl;
}
