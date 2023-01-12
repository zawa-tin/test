#include <numeric>

namespace zawa {

template <class dat_type>
struct gcd_structure {
	using T = dat_type;
	static T op(T a, T b) {
		return std::gcd(a, b);
	}
};

} // namespace zawa
