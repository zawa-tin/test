#pragma once

#include <queue>
#include <vector>
#include <limits>
#include <utility>

namespace zawa {

class BFS {
public:

    BFS(std::size_t n)
        : G(n)
        , dist(n, _inf)
        , prevs(n, -1)
        , route(n, -1) {}

    int add_edge(int from, int to) {
        int res = (int)edges.size();
        edges.push_back({ from, to });
        G[from].emplace_back(res);
        return res;
    }

    std::pair<int, int> get_edge(int id) {
        return edges[id];
    }

    void build(int s) {
        dist[s] = 0;
        std::queue<int> que({ s });
        while (que.size()) {
            int v = que.front();
            que.pop();
            for (auto x : G[v]) {
                auto [_, t] = edges[x];
                if (dist[t] > dist[v] + 1) {
                    dist[t] = dist[v] + 1;
                    prevs[t] = v;
                    route[t] = x;
                    que.emplace(t);
                }
            }
        }
    }

    int inf() {
        return _inf;
    }

    int get_dist(int v) {
        return dist[v];
    }

    int get_prev(int v) {
        return prevs[v];
    }

    int get_route(int v) {
        return route[v];
    }

private:
    static constexpr int _inf = std::numeric_limits<int>::max();
    std::vector<std::pair<int, int>> edges;
    std::vector<std::vector<int>> G;
    std::vector<int> dist;
    std::vector<int> prevs;
    std::vector<int> route;
};

}// namespace zawa
