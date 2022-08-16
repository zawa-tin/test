#pragma once

#include <vector>

namespace zawa {

    template <class T>
    class Accum_1D {
    private:
        std::vector<T> container;
        std::vector<T> accum;

    public:
        Accum_1D(std::vector<T> arr) 
            : container(arr.begin(), arr.end())
            , accum(std::vector<T>(arr.size() + 1)) {

                for (int i = 0 ; i < (int)arr.size() ; i++) {
                    accum[i + 1] = accum[i] + container[i];
                }
        }
        
        Accum_1D(std::vector<T> arr, T elem)
            : container(arr.begin(), arr.end())
            , accum(std::vector<T>(arr.size() + 1, elem)) {
                
                for (int i = 0 ; i < (int)arr.size() ; i++) {
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
