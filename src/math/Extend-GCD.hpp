#pragma once

namespace zawa {

    void rec(long long a, long long b, long long& x, long long& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return;
        }

        rec(b, a % b, y, x);
        
        y -= a / b * x;
    }

    std::pair<long long, long long> extend_gcd(long long a, long long b) {
        long long resx = 0, resy = 0;
        rec(a, b, resx, resy);
        return {resx, resy};
    }

}// namespace zawa
