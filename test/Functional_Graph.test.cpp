#include <vector>
#include <tuple>

namespace zawa {

template <std::size_t log = 63>
class Functional_Graph {
private:
    std::vector<int> fs;
    std::vector<std::vector<int>> table;

public:
    Functional_Graph(const std::vector<int>& as)
        : fs(as.begin(), as.end())
        , table(log, std::vector(as.size(), -1)) {
        table[0] = as;
        for (std::size_t i = 0 ; i + 1 < 63 ; i++) {
            for (std::size_t j = 0 ; j < fs.size() ; j++) {
                table[i + 1][j] = table[i][table[i][j]];
            }
        }
    }

    inline int f(int x) {
        return fs[x];
    }

    int walk(int start, long long step) {
        int res = start;
        for (std::size_t i = 0 ; i < log ; i++) {
            if (step & 1) {
                res = table[i][res];
            }
            step >>= 1;
        }
        return res;
    }

    std::tuple<int, int, int> detect(int start) {
        std::vector used(fs.size(), -1);
        int step = 0;
        int now = start;
        for ( ; ; step++) {
            if (~used[now]) {
                break;
            }
            used[now] = step;
            now = f(now);
        }
        return std::tuple(used[now], now, step - used[now]);
    }

};

}// namespace zawa

#include <iostream>
#include <string>

int main() {
    int n, a;
    std::cin >> n >> a;
    a--;
    std::string k;
    std::cin >> k;
    std::vector bs(n, 0);
    for (auto& b : bs) {
        std::cin >> b;
        b--;
    }
    zawa::Functional_Graph fg(bs);
    if (k.size() <= (size_t)18) {
        std::cout << fg.walk(a, std::stoll(k)) + 1 << std::endl;
    }
    else {
        auto [prev, start, size] = fg.detect(a);
        int mod = 0;
        for (std::size_t i = 0 ; i < k.size() ; i++) {
            mod = (10 * mod + (k[i] - '0')) % size;
        }
        mod += (n / size) * size;
        mod -= prev;
        mod %= size;
        std::cout << fg.walk(start, mod) + 1 << std::endl;
    }
}
