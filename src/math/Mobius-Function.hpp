#pragma once

#include <iostream>
#include <vector>
#include "Eratosthenes-Sieve.hpp"

namespace zawa {

    class Mobius_Function {
    private:
        std::vector<int_fast8_t> table;

    public:
        Mobius_Function(int n) : table(std::vector<int_fast8_t>(n + 1, 1)) {
            Eratosthenes_Sieve siv(n);

            for (int i = 2 ; i <= n ; i++) {
                if (!siv.is_prime(i)) continue;

                for (long long j = i ; j <= n ; j += i) {
                    if (!(j % ((long long)i * i))) {
                        table[j] = 0;
                    }
                    else {
                        table[j] *= -1;
                    }
                }
            }
        }

        int get(int x) {
            return table[x];
        }
    };

}// namespace zawa
