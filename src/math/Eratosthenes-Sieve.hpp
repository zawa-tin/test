#pragma once

#include <vector>

namespace zawa {

    class Eratosthenes_Sieve {
    private:
        std::vector<bool> table;

    public:
        Eratosthenes_Sieve(int n) : table(std::vector<bool>(n + 1, true)) {
            if (n >= 0) table[0] = false;
            if (n >= 1) table[1] = false;
            
            for (long long i = 2 ; i <= n ; i++) {
                if (!table[i]) continue;
                for (long long j = i * i ; j <= n ; j += i) {
                    table[j] = false;
                }
            }
        }

        bool is_prime(int x) {
            return 0 <= x and x < (int)table.size() and table[x];
        }
    };

}// namespace zawa
