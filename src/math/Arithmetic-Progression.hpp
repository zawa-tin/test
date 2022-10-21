#pragma once

namespace zawa {

template <class T>
class Arithmetic_Progression {
private:
    T first_term;
    T common_difference;

    T term(T n) {
        return first_term + (n - 1) * common_difference;
    }
    
    T sum(T n) {
        T end_term = term(n);
        if (n & 1) {
            return ((first_term + end_term) / 2) * n;
        }
        else {
            return (n / 2) * (first_term + end_term);
        }
    }

public:
    Arithmetic_Progression(T s, T d)
        : first_term(s), common_difference(d) {}

    T get(T n) {
        if (n <= 0) {
            return 0;
        }
        return term(n);
    }

    T accumulate(T l, T r) {
        return sum(r) - sum(l - 1);
    }

};

} // namespace zawa
