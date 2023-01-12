#pragma once

#include <vector>
#include <algorithm>

namespace zawa {

template <class T>
class compression {
private:
	std::vector<T> arr;
	std::vector<int> dat;
	std::vector<T> invs;

public:
	compression(const std::vector<T>& arr) : arr(arr), dat(arr.size()), invs(arr.size()) {
		std::vector cp = arr;
		std::sort(cp.begin(), cp.end());	
		cp.erase(std::unique(cp.begin(), cp.end()), cp.end());
		for (std::size_t i = 0 ; i < arr.size() ; i++) {
			dat[i] = std::lower_bound(cp.begin(), cp.end(), arr[i]) - cp.begin();
		}
		for (std::size_t i = 0 ; i < arr.size() ; i++) {
			invs[dat[i]] = arr[i];
		}
	}

	int operator [](int i) {
		return dat[i];
	}

	T inv(int i) {
		return invs[i];
	}

	std::vector<int> get() {
		return dat;
	}
};

} // namespace zawa
