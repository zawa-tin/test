namespace zawa::impl {

template <class T>
struct Cycle_Info {
    T start;
    int length;
};

} // namespace zawa::impl

namespace zawa {

template <class T, class F>
impl::Cycle_Info<T> floyd(T s, const F& nxt, int limit = 50000000) {
    T turtle = s, rabbit = s;
    int check = 0;
    for ( ; check < limit ; check++) {
        turtle = nxt(turtle);
        rabbit = nxt(nxt(rabbit));
        if (turtle == rabbit) {
            break;
        }
    }
    if (check == limit) {
        return { s, -1 };
    }
    rabbit = s;
    while (1) {
        rabbit = nxt(rabbit);
        turtle = nxt(turtle);
        if (rabbit == turtle) {
            break;
        }
    }
    T start = turtle;
    int length = 0;
    while (1) {
        length++;
        turtle = nxt(turtle);
        rabbit = nxt(nxt(rabbit));
        if (turtle == rabbit) {
            break;
        }
    }
    return { start, length };
}

} // namespace zawa

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    long long k;
    std::cin >> k;
    std::vector as(n, 0);
    for (auto& a : as) {
        std::cin >> a;
        a--;
    }
    auto nxt = [&](int now) {
        return as[now];
    };
    auto info = zawa::floyd(0, nxt);
    int ans = 0;
    while (k--) {
        if (ans == info.start) {
            k %= info.length;
        }
        ans = nxt(ans);
    }
    std::cout << ans + 1 << std::endl;
}
