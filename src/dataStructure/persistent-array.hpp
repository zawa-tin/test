#pragma once

#include <vector>
#include <cstring>

namespace zawa {

template <class T, std::size_t M = 20>
class persistent_array {
private:
	struct node;
	using nodeptr = node*;
	struct node {
		T value;
		nodeptr children[M];
	};
	std::vector<nodeptr> roots;

	void build(std::size_t idx, const T& value, nodeptr now) {
		if (idx == 0) {
			now->value = value;
			return;
		}
		if (now->children[idx % M] == nullptr) {
			now->children[idx % M] = new node();
		}
		build(idx / M, value, now->children[idx % M]);
	}

	T get(std::size_t idx, const nodeptr& now) {
		if (idx == 0) {
			return now->value;
		}
		return get(idx / M, now->children[idx % M]);
	}

	nodeptr set(const nodeptr& comp, std::size_t idx, const T& value) {
		nodeptr res = new node();
		if (comp != nullptr) {
			std::memcpy(res->children, comp->children, sizeof(comp->children));
		}
		res->value = (idx == (std::size_t)0 ? value : comp->value);
		if (idx != (std::size_t)0) {
			res->children[idx % M] = set(comp->children[idx % M], idx / M, value);
		}
		return res;
	}
	
public:
	persistent_array(const std::vector<T>& as) {
		roots.push_back(new node());
		for (std::size_t i = 0 ; i < as.size() ; i++) {
			build(i, as[i], roots.front());
		}
	}

	persistent_array(std::size_t n) {
		roots.push_back(new node());
		for (std::size_t i = 0 ; i < n ; i++) {
			build(i, T(), roots.front());
		}
	}

	T get(int time, std::size_t idx) {
		return get(idx, roots[time]);
	}

	void set(int time, std::size_t idx, const T& val) {
		roots.push_back(set(roots[time], idx, val));
		return;
	}

	std::size_t size() {
		return roots.size();
	}
};

} // namespace zawa
