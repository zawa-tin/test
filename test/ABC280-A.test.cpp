#define PROBLEM "https://atcoder.jp/contests/abc280/tasks/abc280_a"

#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int H, W; std::cin >> H >> W;
	int ans = 0;
	for (int _ = 0 ; _ < H ; _++) {
		std::string s; std::cin >> s;
		ans += std::count(s.begin(), s.end(), '#');
	}
	std::cout << ans << std::endl;
}
