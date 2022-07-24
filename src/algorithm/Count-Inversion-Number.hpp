#pragma once

#include <vector>

namespace zawa {

    template <typename T>
    class Count_Inversion_Number {
    private:
        std::vector<T> arr;
        long long count_inversion_number = 0;

        long long sort(int left, int right) {
            if (right - left == 1) return 0LL;

            long long res = 0;
            int mid = left + (right - left) / 2;
            
            res += sort(left, mid);
            res += sort(mid, right);

            std::vector<int> fronts(arr.begin() + left, arr.begin() + mid);
            std::vector<int> backs(arr.begin() + mid, arr.begin() + right);

            int front_idx = 0, back_idx = 0;
            for (int i = left ; i < right ; i++) {
                if (front_idx < fronts.size() and 
                        (back_idx == backs.size() or fronts[front_idx] < backs[back_idx])) {
                    arr[i] = fronts[front_idx++];
                }
                else {
                    arr[i] = backs[back_idx++];
                    res += mid - left - front_idx;
                }
            }

            return res;
        }
    
    public:
        Count_Inversion_Number(std::vector<T>& arr) : arr(arr.begin(), arr.end()) {}

        void build() {
            count_inversion_number = sort(0, arr.size());
        }

        long long get() {
            return count_inversion_number;
        }

        std::vector<T> getSorted() {
            return arr;
        }
    };

} // namespace zawa
