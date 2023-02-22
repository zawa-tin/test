#pragma once

#include <deque>
#include <cassert>

namespace zawa {

template <class T, bool min>
class monotone_CHT {
private:
	struct line {
		T coeff, intercept;
		line(T _coeff, T _intercept) : coeff(_coeff), intercept(_intercept) {}
		T map(T x) {
			return coeff * x + intercept;
		}
	};

	std::deque<line> dat;

	bool is_need(const line& l1, const line& l2, const line& l3) {
		assert(l1.coeff >= l2.coeff and l2.coeff >= l3.coeff);
		return (l1.coeff - l2.coeff) * (l2.intercept - l3.intercept) < (l2.coeff - l3.coeff) * (l1.intercept - l2.intercept);
	}

	bool manage_front(const line& l) {
		if (l.coeff == dat.front().coeff and l.intercept >= dat.front().intercept) {
			return false;
		}
		while (size() >= 2 and !is_need(l, dat.front(), dat[1])) {
			dat.pop_front();
		}
		return true;
	}

	bool manage_back(const line& l) {
		if (l.coeff == dat.back().coeff and l.intercept >= dat.back().intercept) {
			return false;
		}
		while (size() >= 2 and !is_need(dat[size() - 2], dat.back(), l)) {
			dat.pop_back();
		}
		return true;
	}

	void add(const line& l) {
		if (empty()) {
			dat.push_back(l);
			return;
		}
		if (l.coeff >= dat.front().coeff) {
			if (manage_front(l)) {
				dat.push_front(l);
			}
		}
		else if (dat.back().coeff >= l.coeff) {
			if (manage_back(l)) {
				dat.push_back(l);
			}
		}
		else {
			assert(false);
		}
	}

public:

	monotone_CHT() {}

	inline bool empty() {
		return dat.empty();
	}

	inline std::size_t size() {
		return dat.size();
	}

	inline std::deque<line> _dat() {
		return dat;
	}

	void add(T coeff, T intercept) {
		if (!min) {
			coeff *= -1;
			intercept *= -1;
		}
		add(line(coeff, intercept));
	}

	T incremental_query(T x) {
		assert(!empty());
		while (dat.size() >= 2 and dat.front().map(x) >= dat[1].map(x)) {
			dat.pop_front();
		}
		return (min ? 1 : -1) * dat.front().map(x);
	}

	T decremental_query(T x) {
		assert(!empty());
		while (dat.size() >= 2 and dat.back().map(x) >= dat[size() - 2].map(x)) {
			dat.pop_back();
		}
		return (min ? 1 : -1) * dat.back().map(x);
	}

	T query(T x) {
		assert(!empty());
		int left = -1, right = size() - 1;
		while (right - left > 1) {
			int mid = (left + right) >> 1;
			if (dat[mid].map(x) >= dat[mid + 1].map(x)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return (min ? 1 : -1) * dat[right].map(x);
	}
	
};

} // namespace zawa
