#pragma once

#include <vector>

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
        pos += (int)n;
        dat[pos] = val;  
        update(pos);
    }

    void apply(int pos, T val) {
        pos += (int)n;
        dat[pos] = op(dat[pos], val);
        update(pos);
    }

    T query(int l, int r) {
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

    T debug(int pos) {
        return dat[pos];
    }
};

} // namespace zawa
