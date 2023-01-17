#pragma once

#include <random>
#include <iostream>
#include <algorithm>

namespace zawa {

template <std::size_t max_length>
class rollinghash {
public:
	using hash_type = long long;
	std::random_device seed_gen;
	std::mt19937_64 mt;
	hash_type base;
	const hash_type mod = (1ULL << 61ULL) - 1;
	std::vector<hash_type> pows;

public:
	struct info {
		std::size_t len;
		hash_type hash;
		info() : len(0), hash(0) {}
		bool operator==(const info& a) {
			return len == a.len and hash == a.hash;
		}
	};

	rollinghash() : mt(seed_gen()), pows(max_length + 1, 1LL) {
		base = std::clamp((hash_type)mt() % mod, (hash_type)1e9, mod - 1);
		for (std::size_t i = 0 ; i < max_length ; i++) {
			pows[i + 1] = ((__int128_t)pows[i] * base) % mod;
		}
	}

	template <class T>
	std::vector<info> build(const std::vector<T>& A) {
		std::vector<info> res(A.size() + 1, info());	
		for (std::size_t i = 0 ; i < A.size() ; i++) {
			res[i + 1].len = i + 1;
			res[i + 1].hash = ((__int128_t)base * res[i].hash + (__int128_t)A[i]) % mod;
		}
		return res;
	}

	std::vector<info> build(const std::string& s) {
		return build(std::vector(s.begin(), s.end()));
	}

	info hash(const std::vector<info>& H, int l, int r) {
		info res = H[r];
		res.len -= H[l].len;
		res.hash -= ((__int128_t)H[l].hash * pows[r - l]) % mod;
		if (res.hash < 0) {
			res.hash += mod;
		}
		return res;
	}
};

} // namespace zawa
