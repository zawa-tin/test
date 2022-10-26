#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D"

#include "../src/graph/Read-Graph.hpp"

#include <set>

void dfs(const std::vector<std::vector<int>>& G, std::set<int>& st, std::vector<bool>& used, int v) {
    used[v] = true;
    st.emplace(v);
    for (auto x : G[v]) {
        if (used[x]) {
            continue;
        }
        dfs(G, st, used, x);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    auto G = zawa::read_graph(n, m, true, false);
    std::vector group(0, std::set<int>());
    std::vector used(n, false);
    for (int i = 0 ; i < n ; i++) {
        if (used[i]) {
            continue;
        }
        std::set<int> st;
        dfs(G, st, used, i);
        group.emplace_back(st);
    }
    std::vector place(n, 0);
    for (int i = 0 ; i < (int)group.size() ; i++) {
        for (auto x : group[i]) {
            place[x] = i; 
        }
    }
    int q; std::cin >> q;
    for (int _ = 0 ; _ < q ; _++) {
        int u, v; std::cin >> u >> v;
        std::cout << (place[u] == place[v] ? "yes" : "no") << std::endl;
    }
}
