#pragma once

#include <vector>
#include <cassert>
#include <functional>

namespace zawa {

template <class T, T (*op)(T, T), T (*e)()>
class segment_tree {
private:
    std::size_t n;
    std::vector<T> dat;

    void update(int pos) {
        while (pos > 1) {
            pos >>= 1;
            dat[pos] = op(dat[(pos << 1) | 0], dat[(pos << 1) | 1]);
        }
    }

public:

    segment_tree(std::size_t n) : n(n), dat(2 * n, e()) {}

    segment_tree(const std::vector<T>& as) : n(as.size()), dat(2 * as.size(), e()) {
        for (std::size_t i = 0 ; i < n ; i++) {
            dat[i + n] = as[i];
        }
        for (int i = n - 1 ; i >= 1 ; i--) {
            dat[i] = op(dat[(i << 1) | 0], dat[(i << 1) | 1]);
        }
    }

    void set(int pos, T val) {
        assert(0 <= pos and pos < (int)n);
        pos += (int)n;
        dat[pos] = val;  
        update(pos);
    }

    void apply(int pos, T val) {
        assert(0 <= pos and pos < (int)n);
        pos += (int)n;
        dat[pos] = op(dat[pos], val);
        update(pos);
    }

    T query(int l, int r) {
        assert(0 <= l and l < (int)n);
        assert(l <= r and r <= (int)n);
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
        assert(0 <= l and l < (int)n);
        assert(f(e()));
        l += n;
        T sum = e();
        while (1) {
            if (!f(op(sum, dat[l]))) {
            }
            else {
                l++;
                if ((l & (-l)) == l) {
                    break;
                }
                if (l >= (i32)dat.size()) {
                    break;
                }
            }
        }
    }

    T debug(int pos) {
        return dat[pos];
    }
};

} // namespace zawa
