#pragma once

#include <vector>

namespace zawa::impl {

template <class T>
long long sort(std::vector<T>& arr, int left, int right) {
	if (right - left == 1) {
		return 0LL;
	}
	long long res = 0LL;
	int mid = left + ((right - left) >> 1);
	res += sort(arr, left, mid);
	res += sort(arr, mid, right);
	std::vector<T> fronts(arr.begin() + left, arr.begin() + mid);
	std::vector<T> backs(arr.begin() + mid, arr.begin() + right);
	int front_idx = 0, back_idx = 0;
	for (int i = left ; i < right ; i++) {
		if (front_idx < (int)fronts.size() and 
				(back_idx == (int)backs.size() or fronts[front_idx] <= backs[back_idx])) {
			arr[i] = fronts[front_idx++];
		}
		else {
			arr[i] = backs[back_idx++];
			res += mid - left - front_idx;
		}
	}
	return res;
}

} // namespace zawa

namespace zawa {

template <class T>
long long count_inv(const std::vector<T>& in) {
	std::vector arr = in;
	return impl::sort(arr, 0, (int)arr.size());
}

} // namespace zawa
