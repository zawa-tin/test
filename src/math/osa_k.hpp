#pragma once

#include <vector>

namespace zawa {

    class osa_k {
    private:
        std::vector<int> factors;

    public:
        osa_k(int n) : factors(std::vector<int>(n + 1)) {
            if (n >= 1) factors[1] = 1;

            for (long long i = 2 ; i <= n ; i++) {
                if (factors[i]) continue;
                factors[i] = i;

                for (long long j = i * i ; j <= n ; j += i) {
                    if (!factors[j]) {
                        factors[j] = i;
                    }
                }
            }
        }

        std::vector<std::pair<int, int>> factorize(int x) {
            std::vector<std::pair<int, int>> res;
            if (x <= 0 or x >= (int)factors.size()) {
                return res;
            }

            while (x > 1) {
                res.emplace_back(factors[x], 0);
                while (factors[x] == res.back().first) {
                    x /= res.back().first;
                    res.back().second++;
                }
            }

            return res;
        }

        std::vector<int> divisor(int x) {
            std::vector<int> res;

            if (x <= 0 or x > (int)factors.size()) {
                return res;
            }

            auto facs = factorize(x);

            res.emplace_back(1);

            for (auto [p, e] : facs) {
                int sz = (int)res.size();
                for (int i = 0 ; i < sz ; i++) {
                    int v = 1;
                    for (int j = 0 ; j < e ; j++) {
                        v *= p;
                        res.emplace_back(res[i] * v);
                    }
                }
            }

            return res;
        }
    };

}// namespace zawa
