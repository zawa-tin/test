#pragma once

#include <cmath>

namespace zawa {

template <class T, class F>
T binary_search(T ok, T ng, const F& f) {
	while (std::abs(ok - ng) > 1) {
		T mid = ((ok + ng) >> 1);
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
