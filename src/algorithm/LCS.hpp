#pragma once

#include <vector>

namespace zawa {

    template <typename T>
    class LCS {

    private:
        std::vector<T> a, b;
        std::vector<T> res;
        std::vector<std::vector<int>> dp;
        std::vector<std::vector<int>> dir;

        void make(int i, int j) {
            if (i == 0 or j == 0) {
                return;
            }

            if (dir[i][j] == 3) {
                make(i - 1, j - 1);
                res.emplace_back(a[i - 1]);
            }
            else if (dir[i][j] == 2) {
                make(i - 1, j);
            }
            else {
                make(i, j - 1);
            }
        }

    public:
        LCS(std::vector<T>& a, std::vector<T>& b)
            : a(a.begin(), a.end()), 
              b(b.begin(), b.end()), 
              dp(a.size() + 1, std::vector<int>(b.size() + 1)), 
              dir(a.size() + 1, std::vector<int>(b.size() + 1)) {}

        void build() {
            for (int i = 1 ; i < (int)a.size() + 1 ; i++) {
                for (int j = 1 ; j < (int)b.size() + 1 ; j++) {
                    if (a[i - 1] == b[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        dir[i][j] = 3;
                    }
                    else if (dp[i - 1][j] >= dp[i][j - 1]) {
                        dp[i][j] = dp[i - 1][j];
                        dir[i][j] = 2;
                    }
                    else {
                        dp[i][j] = dp[i][j - 1];
                        dir[i][j] = 1;
                    }
                }
            }

            make((int)a.size(), (int)b.size());
        }

        std::vector<T> get() {
            return res;
        }

        int get_size() {
            return dp[a.size()][b.size()];
        }

    };

}// namespace zawa
