#pragma once

#include <vector>
#include <algorithm>

namespace zawa {

template <class T>
class compression {
private:
	std::vector<T> as;
	std::vector<T> uniqued;

public:
	compression(const std::vector<T>& as) : as(as), uniqued(as) {
		std::sort(uniqued.begin(), uniqued.end());
		uniqued.erase(std::unique(uniqued.begin(), uniqued.end()), uniqued.end());
	}

	int operator[](const T& val) {
		return std::lower_bound(uniqued.begin(), uniqued.end(), val) - uniqued.begin();
	}

	int get(std::size_t i) {
		return (*this)[as[i]];
	}

	std::size_t size() {
		return uniqued.size();
	}
};

} // namespace zawa
