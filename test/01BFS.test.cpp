#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../src/graph/01BFS.hpp"

#include <iostream>
// #include <string>

int main() {
    /*
    int h, w; std::cin >> h >> w;
    std::vector grid(h, std::string());
    for (auto& g : grid) {
        std::cin >> g;
    }
    std::vector<std::pair<int, int>> ds = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    zawa::Zero_One_BFS bfs(h * w);
    int dy[] = { 0, 1, 0, -1 };
    int dx[] = { 1, 0, -1, 0 };
    for (int i = 0 ; i < h ; i++) {
        for (int j = 0 ; j < w ; j++) {
            if (grid[i][j] == '#') {
                continue;
            }
            for (int d = 0 ; d < 4 ; d++) {
                if (grid[i][j] == 'R' and d != 0) {
                    continue;
                }
                if (grid[i][j] == 'D' and d != 1) {
                    continue;
                }
                if (grid[i][j] == 'L' and d != 2) {
                    continue;
                }
                if (grid[i][j] == 'U' and d != 3) {
                    continue;
                }
                int ny = i + dy[d], nx = j + dx[d];
                if (!(0 <= ny and ny < h and 0 <= nx and nx < w)) {
                    continue;
                }
                if (grid[ny][nx] == '#') {
                    continue;
                }
                if (grid[i][j] == 'S' or grid[i][j] == 'G' or grid[i][j] == '.') {
                    bfs.add_one_edge(i * w + j, ny * w + nx);
                }
                else {
                    bfs.add_zero_edge(i * w + j, ny * w + nx);
                }
            }
        }
    }
    int s = -1, g = -1;
    for (int i = 0 ; i < h ; i++) {
        for (int j = 0 ; j < w ; j++) {
            if (grid[i][j] == 'S') {
                s = i * w + j;
            }
            if (grid[i][j] == 'G') {
                g = i * w + j;
            }
        }
    }
    bfs.build(s);
    int ans = bfs.get_dist(g);
    std::cout << (ans == bfs.inf() ? -1 : ans) << std::endl;
    */

    std::cout << "Hello World" << std::endl;
}

/*
 * AOJ 3528 Belt Conveyor Maze
 * https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/3528/judge/7100637/C++17
 */
