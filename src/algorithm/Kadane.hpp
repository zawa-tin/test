#pragma once

#include <vector>

namespace zawa {

    template <typename T>
    class Kadane {

    private:
        std::vector<T> arr;
        std::pair<int, int> segment;
        T res;

    public:
        Kadane(std::vector<T>& arr, T init) 
            : arr(arr.begin(), arr.end()), 
              res(init) {}

        void build() {
            T dp = res;
            int left = 0;
            for (int right = 0 ; right < (int)arr.size() ; right++) {
                if (dp + arr[right] < arr[right]) {
                    left = right;
                }
                dp = std::max(dp + arr[right], arr[right]);

                if (res < dp) {
                    segment = {left, right};
                }
                res = std::max(res, dp);
            }
            segment.second++;
        }

        T get() {
            return res;
        }

        std::pair<int, int> get_seg() {
            return segment;
        }
    };

}// namespace zawa
