#pragma once

#include <vector>
#include <cassert>

namespace zawa {

template <class structure>
class lazySegmentTree {
	// valueMonoid prodの時の演算
	using V = typename structure::valueMonoid::valueType;
	// operatorMonoid updateの時の演算
	using O = typename structure::operatorMonoid::valueType;
private:
	// prodの単位元
	static constexpr V vId = structure::valueMonoid::identity;
	// updateの単位元
	static constexpr O oId = structure::operatorMonoid::identity;

	struct node {
		V value;
		O lazy;
		node() : value(vId), lazy(oId) {}
	};

	// @brief ノードvの左子の添字を返す
	constexpr std::size_t left(std::size_t v) const {
		return v << 1;
	}
	// @brief ノードvの右子の添字を返す
	constexpr std::size_t right(std::size_t v) const {
		return v << 1 | 1;
	}
	// @brief ノードvの親の添字を返す。
	constexpr std::size_t parent(std::size_t v) const {
		return (v >> 1);
	}

	std::size_t N;
	std::size_t powTwo;
	std::vector<node> dat;

	// @brief 遅延した値を子に伝播する
	void propagate(std::size_t v) {
		if (dat[v].lazy == oId) {
			return;
		}
		dat[v].value = structure::mapping(dat[v].value, dat[v].lazy);
		if (right(v) < dat.size()) {
			dat[left(v)].lazy = structure::operatorMonoid::operation(dat[left(v)].lazy, dat[v].lazy);
			dat[right(v)].lazy = structure::operatorMonoid::operation(dat[right(v)].lazy, dat[v].lazy);
		}
		dat[v].lazy = oId;
	}

	// @brief 内部更新用
	// LRがクエリの範囲、lrがvの持つ範囲
	void update(std::size_t L, std::size_t R, std::size_t l, std::size_t r, std::size_t v, const O& value) {
		// 先延ばししていたものを評価する
		propagate(v);

		// まったくかぶってない時、特に何もしない
		if (R <= l or r <= L) {
			return;
		}

		// lrがLRにまたがっている時、先延ばしにする
		if (L <= l and r <= R) {
			dat[v].lazy = structure::operatorMonoid::operation(dat[v].lazy, value);
			propagate(v);
		}
		// 子を計算する場合
		else {
			assert(right(v) < dat.size());
			std::size_t childRange = (r - l) >> 1;
			update(L, R, l, l + childRange, left(v), value);
			update(L, R, l + childRange, r, right(v), value);
			dat[v].value = structure::valueMonoid::operation(dat[left(v)].value, dat[right(v)].value);
		}
	}

	// @brief 内部計算用
	// LRがクエリの範囲、lrがvの持つ範囲
	V prod(std::size_t L, std::size_t R, std::size_t l, std::size_t r, std::size_t v) {

		// 区間が被ってない時、単位元を返す
		if (R <= l or r <= L) {
			return vId;
		}

		// 先延ばしが許されなくなったので遅延評価する
		propagate(v);

		// lrがLRにすっぽりおさまっている時、そのノードの値を掛け合わせる
		if (L <= l and r <= R) {
			return dat[v].value;
		}
		// 子を辿る
		else {
			V res = vId;
			std::size_t childRange = (r - l) >> 1;
			assert(right(v) < dat.size());
			res = structure::valueMonoid::operation(res, prod(L, R, l, l + childRange, left(v)));
			res = structure::valueMonoid::operation(res, prod(L, R, l + childRange, r, right(v)));
			return res;
		}
	}

public:
	// @brief A = ( vId, vId, ... , vId ), |A| = Nとする
	// @param N |A|
	lazySegmentTree(std::size_t _N) : N(_N) {
		std::size_t sz = 1;
		while (sz < N) {
			sz <<= 1;
		}
		powTwo = sz;
		dat.resize((sz << 1));
	}

	// @brief Aを引数の列で初期化する
	// @param A 扱う列
	lazySegmentTree(const std::vector<V>& A) : N(A.size()) {
		std::size_t sz = 1;
		while (sz < N) {
			sz <<= 1;
		}
		powTwo = sz;
		dat.resize((sz << 1));
		for (std::size_t i = 0 ; i < A.size() ; i++) {
			dat[i + powTwo].value = A[i];
		}
		for (std::size_t i = powTwo - 1 ; i > 0 ; i--) {
			dat[i].value = structure::valueMonoid::operation(dat[left(i)].value, dat[right(i)].value);
		}
	}	
	
	// @brief A_l .. A_{r - 1}にvalueで列を更新する
	// @param L 左
	// @param R 右、半開区間で与える必要がある
	// @param value 更新させる値
	void update(std::size_t L, std::size_t R, const O& value) {
		assert(0 <= L and R <= N);
		assert(L < R);
		update(L, R, 0, powTwo, 1, value);
	}

	// @brief A_l .. A_R の総積(総valueMonoid::operation)を得る
	// @param L 左
	// @param R 右、半開区間で与える必要がある
	// @return 計算結果
	V prod(std::size_t L, std::size_t R) {
		assert(0 <= L and R <= N);
		if (L == R) {
			return vId;
		}
		return prod(L, R, 0, powTwo, 1);
	}

	// @brief デバッグ用、datを返す
	// @return dat
	inline std::vector<node> _dat() const {
		return dat;
	}
};

} // namespace zawa
