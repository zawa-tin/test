#include "../src/utility/monoid/minMonoid.hpp"
#include "../src/dataStructure/segmentTree.hpp"

#include <iostream>
#include <vector>
#include <functional>

int main() {
	int N; std::cin >> N;
	std::vector a(N, 0);
	for (auto& ai : a) {
		std::cin >> ai;
	}
	zawa::segmentTree<zawa::minMonoid<int>> seg(a);
	long long ans = 0LL;
	for (int i = 0 ; i < N ; i++) {
		auto f = [&](int p) -> bool {
			return p >= a[i];
		};
		int l = seg.minLeft(i, f), r = seg.maxRight(i, f);
		ans += (long long)(i - l + 1) * (r - i) * a[i];
	}
	std::cout << ans << std::endl;
}
