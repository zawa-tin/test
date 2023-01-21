#pragma once

#include <cstddef>

namespace zawa {

template <class T, class F, std::size_t up = 80>
T binary_search_ld(T ok, T ng, const F& f) {
	for (std::size_t _ = 0 ; _ < up ; _++) {
		T mid = (ok + ng) / 2;
		if (f(mid)) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	return ok;
}

}
