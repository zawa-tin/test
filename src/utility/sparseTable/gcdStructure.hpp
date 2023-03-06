#include <numeric>

namespace zawa {

template <class T>
struct gcdStructure {
	using valueType = T;
	static valueType operation(const valueType& a, const valueType& b) {
		return std::gcd(a, b);
	}
};

} // namespace zawa
