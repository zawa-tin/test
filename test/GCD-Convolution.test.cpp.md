---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Eratosthenes-Sieve.hpp
    title: "Eratosthenes Sieve (\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
  - icon: ':heavy_check_mark:'
    path: src/math/GCD-Convolution.hpp
    title: "GCD Convlution (\u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\u3001\u7D04\u6570\
      \u96C6\u5408\u306E\u9AD8\u901F\u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\u5909\
      \u63DB)"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/GCD-Convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\
    \n\n#include <iostream>\n#line 2 \"src/math/GCD-Convolution.hpp\"\n\n#include\
    \ <vector>\n#include <algorithm>\n#line 2 \"src/math/Eratosthenes-Sieve.hpp\"\n\
    \n#line 4 \"src/math/Eratosthenes-Sieve.hpp\"\n\nnamespace zawa {\n\n    class\
    \ Eratosthenes_Sieve {\n    private:\n        std::vector<bool> table;\n\n   \
    \ public:\n        Eratosthenes_Sieve(int n) : table(std::vector<bool>(n + 1,\
    \ true)) {\n            if (n >= 0) table[0] = false;\n            if (n >= 1)\
    \ table[1] = false;\n            \n            for (long long i = 2 ; i <= n ;\
    \ i++) {\n                if (!table[i]) continue;\n                for (long\
    \ long j = i * i ; j <= n ; j += i) {\n                    table[j] = false;\n\
    \                }\n            }\n        }\n\n        bool is_prime(int x) {\n\
    \            return 0 <= x and x < (int)table.size() and table[x];\n        }\n\
    \    };\n\n}// namespace zawa\n#line 6 \"src/math/GCD-Convolution.hpp\"\n\nnamespace\
    \ zawa {\n\n    template <typename T>\n    class GCD_Convolution {\n    private:\
    \ \n        Eratosthenes_Sieve sieve;\n\n    public:\n        GCD_Convolution(int\
    \ n) : sieve(Eratosthenes_Sieve(n)) {}\n        \n        std::vector<T> fast_zeta_transform(const\
    \ std::vector<T>& f) {\n            std::vector<T> res(f.begin(), f.end());\n\n\
    \            for (int i = 1 ; i <= (int)(f.size()) ; i++) {\n                if\
    \ (!sieve.is_prime(i)) continue;\n\n                for (int j = (int)res.size()\
    \ / i ; j >= 1 ; j--) {\n                    res[j - 1] += res[j * i - 1];\n \
    \               }\n            }\n\n            return res;\n        }\n\n   \
    \     std::vector<T> fast_mobius_transform(const std::vector<T>& F) {\n      \
    \      std::vector<T> res(F.begin(), F.end());\n\n            for (int i = 1 ;\
    \ i <= (int)(F.size()) ; i++) {\n                if (!sieve.is_prime(i)) continue;\n\
    \n                for (int j = 1 ; j * i <= (int)(F.size()) ; j++) {\n       \
    \             res[j - 1] -= res[j * i - 1];\n                }\n            }\n\
    \n            return res;\n        }\n\n        std::vector<T> convolution(const\
    \ std::vector<T>& f, const std::vector<T>& g) {\n            std::vector<T> F\
    \ = fast_zeta_transform(f);\n            std::vector<T> G = fast_zeta_transform(g);\n\
    \            \n            std::vector<T> H(std::min(F.size(), G.size()));\n \
    \           for (int i = 0 ; i < (int)(H.size()) ; i++) {\n                H[i]\
    \ = F[i] * G[i];\n            }\n\n            return fast_mobius_transform(H);\n\
    \        }\n    };\n\n}// namespace zawa\n#line 1 \"src/math/modint.hpp\"\nnamespace\
    \ zawa {\n\n    template<long long mod>\n    class modint {\n    private:\n  \
    \      long long x;\n\n    public:\n        modint() : x(0) {}\n        \n   \
    \     modint(long long x) : x((x % mod + mod) % mod) {}\n\n        modint& operator+=(modint\
    \ p) {\n            x += p.x;\n            if (x >= mod) x -= mod;\n         \
    \   return *this;\n        }\n\n        modint& operator-=(modint p) {\n     \
    \       x += mod - p.x;\n            if (x >= mod) x -= mod;\n            return\
    \ *this;\n        }\n\n        modint& operator*=(modint p) {\n            x =\
    \ (1LL * x * p.x % mod);\n            return *this;\n        }\n\n        modint&\
    \ operator/=(modint p) {\n            *this *= p.inv();\n            return *this;\n\
    \        }\n\n        modint operator-() const {\n            return modint(-x);\n\
    \        }\n\n        modint operator+(const modint& p) const {\n            return\
    \ modint(*this) += p;\n        }\n\n        modint operator-(const modint& p)\
    \ const {\n            return modint(*this) -= p;\n        }\n\n        modint\
    \ operator*(const modint& p) const {\n            return modint(*this) *= p;\n\
    \        }\n\n        modint operator/(const modint& p) const {\n            return\
    \ modint(*this) /= p;\n        }\n\n        long long val() {\n            return\
    \ x;\n        }\n\n        modint pow(long long p) {\n            modint res(1),\
    \ val(x);\n            while(p) {\n                if (p & 1) res *= val;\n  \
    \              val *= val;\n                p >>= 1;\n            }\n        \
    \    return res;\n        }\n\n        modint inv() {\n            return pow(mod\
    \ - 2);\n        }\n    };\n\n}// namespace zawa\n#line 6 \"test/GCD-Convolution.test.cpp\"\
    \n\nusing mint = zawa::modint<998244353>;\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<mint> as(n), bs(n);\n    for (auto& a : as) {\n     \
    \   int t;\n        std::cin >> t;\n        a = mint(t);\n    }\n    for (auto&\
    \ b : bs) {\n        int t;\n        std::cin >> t;\n        b = mint(t);\n  \
    \  }\n\n    zawa::GCD_Convolution<mint> conv(n);\n    auto ans = conv.convolution(as,\
    \ bs);\n    for (int i = 0 ; i < (int)(ans.size()) ; i++) {\n        std::cout\
    \ << ans[i].val() << (i + 1 == (int)ans.size() ? '\\n' : ' ');\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ <iostream>\n#include \"../src/math/GCD-Convolution.hpp\"\n#include \"../src/math/modint.hpp\"\
    \n\nusing mint = zawa::modint<998244353>;\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<mint> as(n), bs(n);\n    for (auto& a : as) {\n     \
    \   int t;\n        std::cin >> t;\n        a = mint(t);\n    }\n    for (auto&\
    \ b : bs) {\n        int t;\n        std::cin >> t;\n        b = mint(t);\n  \
    \  }\n\n    zawa::GCD_Convolution<mint> conv(n);\n    auto ans = conv.convolution(as,\
    \ bs);\n    for (int i = 0 ; i < (int)(ans.size()) ; i++) {\n        std::cout\
    \ << ans[i].val() << (i + 1 == (int)ans.size() ? '\\n' : ' ');\n    }\n}\n"
  dependsOn:
  - src/math/GCD-Convolution.hpp
  - src/math/Eratosthenes-Sieve.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/GCD-Convolution.test.cpp
  requiredBy: []
  timestamp: '2022-08-22 15:46:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/GCD-Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/GCD-Convolution.test.cpp
- /verify/test/GCD-Convolution.test.cpp.html
title: test/GCD-Convolution.test.cpp
---
