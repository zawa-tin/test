#pragma once

#include <vector>

namespace zawa {

template <class structure>
class sparse_table {
private:
	using T = typename structure::T;
	std::vector<int> ls;
	std::vector<std::vector<T>> dat;

public:

	sparse_table(const std::vector<T>& as) : ls(as.size() + 1, 0) {
		for (int i = 1 ; i < (int)ls.size() ; i++) {
			ls[i] = ls[i - 1] + (i >> (ls[i - 1] + 1));
		}
		dat = std::vector(ls.back() + 1, as);
		dat[0] = as;
		for (int i = 1 ; i < (int)dat.size() ; i++) {
			int pt = (1 << i);
			for (int j = 0 ; j + pt - 1 < (int)dat[i].size() ; j++) {
				dat[i][j] = structure::op(dat[i - 1][j], dat[i - 1][j + (pt >> 1)]);
			}
		}
	}

	T query(int l, int r) {
		int now = ls[r - l];
		return structure::op(dat[now][l], dat[now][r - (1 << now)]);
	}

	const std::vector<std::vector<T>>& get() {
		return dat;
	}

};

} // namespace zawa
