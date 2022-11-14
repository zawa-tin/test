#pragma once

#include <vector>
#include <deque>
#include <limits>
#include <utility>
#include <algorithm>

namespace zawa {

class Zero_One_BFS {
public:

    struct edge {
        int from, to;
        bool cost;
    };

    Zero_One_BFS(std::size_t n)
        : G(n, std::vector(0, 0))
        , edges(0, edge())
        , dist(n, _inf)
        , prevs(n, -1)
        , route(n, -1) {}

    int add_zero_edge(int from, int to) {
        return add_edge(from, to, false);
    }

    int add_one_edge(int from, int to) {
        return add_edge(from, to, true);
    }

    inline edge get_edge(int id) {
        return edges[id];
    }

    void build(int s) {
        std::fill(dist.begin(), dist.end(), _inf);
        std::fill(prevs.begin(), prevs.end(), -1);
        std::fill(route.begin(), route.end(), -1);
        dist[s] = 0;
        std::deque<int> deq({ s });
        while (deq.size()) {
            int v = deq.front();
            deq.pop_front();
            for (auto x : G[v]) {
                auto [_, t, cost] = edges[x];
                if (dist[t] > dist[v] + (int)cost) {
                    dist[t] = dist[v] + (int)cost;
                    prevs[t] = v;
                    route[t] = x;
                    if (cost) {
                        deq.push_back(t);
                    }
                    else {
                        deq.push_front(t);
                    }
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
    std::vector<std::vector<int>> G;
    std::vector<edge> edges;
    std::vector<int> dist;
    std::vector<int> prevs;
    std::vector<int> route;
    
    int add_edge(int from, int to, bool cost) {
        int res = (int)edges.size();
        edges.push_back({ from, to, cost });
        G[from].push_back(res);
        return res;
    }
};

}// namespace zawa
