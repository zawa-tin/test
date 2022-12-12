#pragma once

#include <vector>
#include <cassert>
#include <functional>

namespace zawa {

template <class T, T (*op)(T, T), T (*e)()>
class segment_tree {
private:
    int n;
    std::vector<T> dat;

    void update(int pos) {
        while (pos > 1) {
            pos >>= 1;
            dat[pos] = op(dat[(pos << 1) | 0], dat[(pos << 1) | 1]);
        }
    }

public:

    segment_tree(int n) : n(n), dat(2 * n, e()) {}

    segment_tree(const std::vector<T>& as) : n(as.size()), dat(2 * as.size(), e()) {
        for (int i = 0 ; i < n ; i++) {
            dat[i + n] = as[i];
        }
        for (int i = n - 1 ; i >= 1 ; i--) {
            dat[i] = op(dat[(i << 1) | 0], dat[(i << 1) | 1]);
        }
    }

    void set(int pos, T val) {
        assert(0 <= pos and pos < n);
        pos += n;
        dat[pos] = val;  
        update(pos);
    }

    void apply(int pos, T val) {
        assert(0 <= pos and pos < n);
        pos += n;
        dat[pos] = op(dat[pos], val);
        update(pos);
    }

    T query(int l, int r) {
        assert(0 <= l and l < n);
        assert(l <= r and r <= n);
        l += n;
        r += n;
        T ans = e();
        while (l < r) {
            if (l & 1) {
                ans = op(ans, dat[l++]);
            }
            if (r & 1) {
                ans = op(ans, dat[--r]);
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }

    T all_prod() {
        return dat[1];
    }

    int max_right(int l, const std::function<bool(int)>& f) {
        assert(0 <= l and l < n);
        int r = 2 * n;
        l += n;
        T sum = e();
        auto down_tree = [&](int v) -> int {
            while (v < n) {
                if (f(op(sum, dat[(v << 1) | 0]))) {
                    sum = op(sum, dat[(v << 1) | 0]);
                    v = ((v << 1) | 1);
                }
                else {
                    v = ((v << 1) | 0);
                }
            }
            return v - n;
        };
        int cnt = 0;
        for ( ; l < r ; cnt++) {
            if (l & 1) {
                if (!f(op(sum, dat[l]))) {
                    return down_tree(l);
                }
                sum = op(sum, dat[l++]);
            }
            r -= (r & 1);
            l >>= 1;
            r >>= 1;
        }
        while (cnt--) {
            r <<= 1;
            if (((r | 1) << cnt) <= 2 * n) {
                if (!f(op(sum, dat[r]))) {
                    return down_tree(r);
                }
                else {
                    sum = op(sum, dat[r++]);
                }
            }
        }
        return n;
    }

    T debug(int pos) {
        return dat[pos];
    }
};

} // namespace zawa
