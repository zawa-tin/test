#pragma once

#include <cmath>

namespace zawa {
    
    template <class T, class F>
    T binary_search(T ac, T wa, const F& judge) {
        while (abs(ac - wa) > 1) {
            T mid = (ac + wa) >> 1;
            if (judge(mid)) {
                ac = mid; 
            }
            else {
                wa = mid;
            }
        }

        return ac;
    }

}// namespace zawa
