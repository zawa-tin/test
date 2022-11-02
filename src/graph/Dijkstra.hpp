#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <limits>

namespace zawa {

template <class COST>
class Dijkstra {
public:
    Dijkstra(std::size_t n) 
        : G(n) 
        , dist(n, _inf) 
        , prevs(n, -1) 
        , route(n, -1) {}

    struct edge {
        int from, to;
        COST cost;
    };

    int add_edge(int from, int to, COST cost) {
        int res = (int)edges.size();
        edges.push_back({ from, to, cost });
        G[from].emplace_back(res);
        return res;
    }

    edge get_edge(int id) {
        return edges[id];
    }

    void build(int s) {
        using pci = std::pair<COST, int>;
        dist[s] = 0;
        std::priority_queue<pci, std::vector<pci>, std::greater<pci>> que;
        que.emplace(0, s);
        while (que.size()) {
            auto [d, v] = que.top();
            que.pop();
            if (dist[v] < d) {
                continue;
            }
            for (auto id : G[v]) {
                edge e = edges[id];
                if (dist[e.to] > d + e.cost) {
                    dist[e.to] = d + e.cost;
                    prevs[e.to] = v;
                    route[e.to] = id;
                    que.emplace(dist[e.to], e.to);
                }
            }
        }
    }

    COST inf() {
        return _inf;
    }

    COST get_dist(int v) {
        return dist[v];
    }

    int get_prev(int v) {
        return prevs[v];
    }

    int get_route(int v) {
        return route[v];
    }

private:
    static constexpr COST _inf = std::numeric_limits<COST>::max();
    std::vector<edge> edges;
    std::vector<std::vector<int>> G; 
    std::vector<COST> dist;
    std::vector<int> prevs;
    std::vector<int> route;
};

} // namespace zawa
