#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/6/ITP1_6_A"

#include "../src/dataStructure/persistent-array.hpp"

#include <iostream>

int main() {
	int n; std::cin >> n;
	zawa::persistent_array<int> pa(n);
	for (int i = 0 ; i < n ; i++) {
		int a; std::cin >> a;
		pa.set(pa.size() - 1, i, a);
	}
	for (int i = 0 ; i < (n + 1) / 2 ; i++) {
		int f = pa.get(pa.size() - 1, i);
		int b = pa.get(pa.size() - 1, n - i - 1);
		pa.set(pa.size() - 1, i, b);
		pa.set(pa.size() - 1, n - i - 1, f);
	}
	for (int i = 0 ; i < n ; i++) {
		std::cout << pa.get(pa.size() - 1, i) << (i + 1 == n ? '\n' : ' ');
	}
}
