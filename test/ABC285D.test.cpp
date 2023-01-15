#include "../src/graph/simple/topo-sort.hpp"
#include "../src/algorithm/compression.hpp"

#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main() {
	int n; std::cin >> n;
	std::vector<std::string> buc;
	std::vector<std::pair<std::string, std::string>> ps(n);
	for (auto& [s, t] : ps) {
		std::cin >> s >> t;
		buc.push_back(s);
		buc.push_back(t);
	}
	zawa::compression comp(buc);
	std::vector<std::vector<int>> G(comp.size());
	for (const auto& [s, t] : ps) {
		G[comp[s]].emplace_back(comp[t]);
	}
	std::cout << (zawa::topo_sort(G).ok() ? "Yes" : "No") << std::endl;
}

/*
 * AtCoder Beginner Contest 285 - D Change Usernames
 * https://atcoder.jp/contests/abc285/submissions/38081790
 */
