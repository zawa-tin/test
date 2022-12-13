#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <limits>

namespace zawa {

template <class cost_type>
class range_edge_graph {
private:
    int n;
    std::vector<std::vector<std::pair<int, cost_type>>> G;

    void add_edge(int u, int v, cost_type cost) {
        if (u >= 3 * n) {
            u -= 2 * n;
        }
        G[u].emplace_back(v, cost);
    }

public:
    range_edge_graph(int n) : n(n), G(3 * n) {
        for (int i = 1 ; i < n ; i++) {
            int child_l = ((i << 1) | 0), child_r = ((i << 1 | 1));
            add_edge(i, child_l, 0);
            add_edge(i, child_r, 0);
            add_edge(child_l + 2 * n, i + 2 * n, 0);
            add_edge(child_r + 2 * n, i + 2 * n, 0);
        }
    }

    void add_edge(int ul, int ur, int vl, int vr, cost_type cost) {
        int id = G.size();
        for (int l = ul + n, r = ur + n ; l < r ; l >>= 1, r >>= 1) {
            if (l & 1) {
                add_edge(l + 2 * n, id, 0);
                l++;
            }
            if (r & 1) {
                r--;
                add_edge(r + 2 * n, id, 0);
            }
        }
        std::vector<std::pair<int, cost_type>> node;
        for (int l = vl + n, r = vr + n ; l < r ; l >>= 1, r >>= 1) {
            if (l & 1) {
                node.emplace_back(l, cost);
                l++;
            }
            if (r & 1) {
                r--;
                node.emplace_back(r, cost);
            }
        }
        G.push_back(node);
    }

    std::vector<cost_type> dijkstra(int s, cost_type sup = std::numeric_limits<cost_type>::max()) {
        std::priority_queue<
            std::pair<cost_type, int>, 
            std::vector<std::pair<cost_type, int>>, 
            std::greater<std::pair<cost_type, int>>
                > que;
        que.emplace((cost_type)0, s + n);
        std::vector<cost_type> dist(G.size(), sup);
        dist[s + n] = (cost_type)0;
        while (que.size()) {
            auto [d, v] = que.top();
            que.pop();
            if (d > dist[v]) {
                continue;
            }
            for (auto [x, cost] : G[v]) {
                if (dist[x] > d + cost) {
                    dist[x] = d + cost;
                    que.emplace(d + cost, x);
                }
            }
        }
        return std::vector<cost_type>(dist.begin() + n, dist.begin() + 2 * n);
    }

};

} // namespace zawa
