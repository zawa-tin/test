#pragma once

#include <vector>
#include <cassert>

namespace zawa {

template <class structure>
class sparseTable {
private:
	using T = typename structure::valueType;
	std::vector<int> L;
	std::vector<std::vector<T>> dat;

public:

	sparseTable(const std::vector<T>& A) : L(A.size() + 1, 0) {
		for (int i = 1 ; i < (int)L.size() ; i++) {
			L[i] = L[i - 1] + (i >> (L[i - 1] + 1));
		}
		dat = std::vector(L.back() + 1, A);
		for (int i = 1 ; i < (int)dat.size() ; i++) {
			int pt = (1 << i);
			for (int j = 0 ; j + pt - 1 < (int)dat[i].size() ; j++) {
				dat[i][j] = structure::operation(dat[i - 1][j], dat[i - 1][j + (pt >> 1)]);
			}
		}
	}

	T query(int l, int r) {
		assert(0 <= l and l < (int)dat[0].size());
		assert(l <= r and r <= (int)dat[0].size());
		int now = L[r - l];
		return structure::operation(dat[now][l], dat[now][r - (1 << now)]);
	}

	inline std::vector<std::vector<T>> _dat() const {
		return dat;
	}

};

} // namespace zawa
