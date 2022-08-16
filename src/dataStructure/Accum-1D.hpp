#pragma once

#include <vector>

namespace zawa {

    template <class T>
    class Accum_1D {
    private:
        std::vector<T> container;
        std::vector<T> accum;

    public:
        Accum_1D(const std::vector<T>& arr) 
            : container(arr.begin(), arr.end())
            , accum(std::vector<T>(arr.size() + 1)) {}
        
        Accum_1D(const std::vector<T>& arr, T elem)
            : container(arr.begin(), arr.end())
            , accum(std::vector<T>(arr.size() + 1, elem)) {}

        Accum_1D(int n)
            : container(n)
            , accum(n + 1) {}

        Accum_1D(int n, T elem)
            : container(n)
            , accum(n + 1, elem) {}

        void set(int idx, T val) {
            container[idx] = val;
        }

        void add(int idx, T val) {
            container[idx] += val;
        }

        void build() {
            for (int i = 0 ; i < (int)container.size() ; i++) {
                accum[i + 1] = accum[i] + container[i];
            }
        }

        T get(int idx) {
            return container[idx];
        }

        T query(int l, int r) {
            return accum[r] - accum[l];
        }
        
    };

}// namespace zawa
