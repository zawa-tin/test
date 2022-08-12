#pragma once

#include "factorize.hpp"

namespace zawa {
    
    long long euler_function(long long x) {
        long long res = x;

        for (auto v : zawa::factorize(x)) {
            res /= v.first;
            res *= v.first - 1;
        }

        return res;
    }

}// namespace zawa
