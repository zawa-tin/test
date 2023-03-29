#pragma once

#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cmath>

namespace zawa {

std::vector<std::tuple<int, int, int>> mo(int N, const std::vector<std::pair<int, int>>& Q) {
	int sq = std::sqrt(Q.size() + 1);
	std::vector tmp((N + sq - 1) / sq, std::vector(0, std::tuple(0, 0, 0)));
	for (int i = 0 ; i < (int)Q.size() ; i++)
		tmp[Q[i].first / sq].emplace_back(Q[i].second, Q[i].first, i);
	std::vector res(0, std::tuple(0, 0, 0));
	for (int i = 0 ; i < (int)tmp.size() ; i++) {
		std::sort(tmp[i].begin(), tmp[i].end());
		if (i & 1) std::reverse(tmp[i].begin(), tmp[i].end());
		for (const auto& [r, l, index] : tmp[i]) res.emplace_back(l, r, index);
	}
	return res;
}

}// namespace zawa
