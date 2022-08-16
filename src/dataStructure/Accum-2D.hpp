#pragma once

#include <iostream>
#include <utility>
#include <vector>

namespace zawa {

    template <class T>
    class Accum_2D {
    private:
        std::vector<std::vector<T>> container;
        std::vector<std::vector<T>> accum;

    public:
        Accum_2D(const std::vector<std::vector<T>>& arr)
            : container(arr.begin(), arr.end())
            , accum(std::vector<std::vector<T>>(arr.size() + 1, std::vector<T>(arr[0].size() + 1))) {}

        Accum_2D(const std::vector<std::vector<T>>& arr, T elem)
            : container(arr.begin(), arr.end())
            , accum(std::vector<std::vector<T>>(arr.size() + 1, std::vector<T>(arr[0].size() + 1, elem))) {}

        Accum_2D(int h, int w)
            : container(std::vector<std::vector<T>>(h, std::vector<T>(w)))
            , accum(std::vector<std::vector<T>>(h + 1, std::vector<T>(w + 1))) {}

        Accum_2D(int h, int w, T elem)
            : container(std::vector<std::vector<T>>(h, std::vector<T>(w)))
            , accum(std::vector<std::vector<T>>(h + 1, std::vector<T>(w + 1, elem))) {}

        void set(int y, int x, T val) {
            container[y][x] = val;
        }

        void add(int y, int x, T val) {
            container[y][x] += val;
        }

        void build() {
            for (int i = 0 ; i < (int)container.size() ; i++) {
                for (int j = 0 ; j < (int)container[i].size() ; j++) {
                    accum[i + 1][j + 1] = accum[i][j + 1] + accum[i + 1][j] - accum[i][j] + container[i][j];
                }
            }
        }

        T get(int y, int x) {
            return container[y][x];
        }

        T query(int y1, int x1, int y2, int x2) {
            return accum[y2][x2] - accum[y1][x2] - accum[y2][x1] + accum[y1][x1];
        }

        T query(std::pair<int, int> p1, std::pair<int, int> p2) {
            return query(p1.first, p1.second, p2.first, p2.second);
        }

        void print() {
            for (auto y : accum) {
                for (int i = 0 ; i < (int)y.size() ; i++) std::cout << y[i] << (i == (int)y.size() - 1 ? '\n' : ' ');
                std::cout << std::endl;
            }
        }

    };

}// namespace zawa
