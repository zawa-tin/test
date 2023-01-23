---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/gcd-convolution.hpp
    title: "gcd-convlution (\u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\u30FB\u7D04\u6570\
      \u7CFB\u306E\u9AD8\u901F\u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\
      )"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: src/math/prime-sieve.hpp
    title: "prime-sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
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
  bundledCode: "#line 1 \"test/gcd-convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\
    \n\n#line 2 \"src/math/gcd-convolution.hpp\"\n\n#line 2 \"src/math/prime-sieve.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\nclass prime_sieve {\nprivate:\n\t\
    std::vector<bool> sieve;\n\npublic:\n\tprime_sieve() {}\n\tprime_sieve(std::size_t\
    \ n) : sieve(n + 1, true) {\n\t\tif (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t\
    }\n\t\tif (n >= 1) {\n\t\t\tsieve[1] = false;\n\t\t}\n\t\tfor (std::size_t i =\
    \ 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (std::size_t j = i *\
    \ i ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j] = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\tbool operator[](std::size_t i) {\n\t\treturn sieve[i];\n\t}\n};\n\n\
    }// namespace zawa\n#line 4 \"src/math/gcd-convolution.hpp\"\n\n#line 6 \"src/math/gcd-convolution.hpp\"\
    \n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <typename T>\nclass gcd_convolution\
    \ {\nprivate: \n\tprime_sieve sieve;\n\npublic:\n\tgcd_convolution(std::size_t\
    \ n) : sieve(n) {}\n\t\n\tstd::vector<T> fast_zeta_transform(const std::vector<T>&\
    \ f) {\n\t\tstd::vector<T> res(f.begin(), f.end());\n\t\tfor (int i = 1 ; i <=\
    \ (int)(f.size()) ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (int j = (int)res.size()\
    \ / i ; j >= 1 ; j--) {\n\t\t\t\t\tres[j - 1] += res[j * i - 1];\n\t\t\t\t}\n\t\
    \t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T> fast_mobius_transform(const\
    \ std::vector<T>& F) {\n\t\tstd::vector<T> res(F.begin(), F.end());\n\t\tfor (int\
    \ i = 1 ; i <= (int)(F.size()) ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (int\
    \ j = 1 ; j * i <= (int)(F.size()) ; j++) {\n\t\t\t\t\tres[j - 1] -= res[j * i\
    \ - 1];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T> convolution(const\
    \ std::vector<T>& f, const std::vector<T>& g) {\n\t\tstd::vector<T> F = fast_zeta_transform(f);\n\
    \t\tstd::vector<T> G = fast_zeta_transform(g);\n\t\tstd::vector<T> H(std::min(F.size(),\
    \ G.size()));\n\t\tfor (int i = 0 ; i < (int)(H.size()) ; i++) {\n\t\t\tH[i] =\
    \ F[i] * G[i];\n\t\t}\n\t\treturn fast_mobius_transform(H);\n\t}\n};\n\n}// namespace\
    \ zawa\n#line 1 \"src/math/modint.hpp\"\nnamespace zawa {\n\n    template<long\
    \ long mod>\n    class modint {\n    private:\n        long long x;\n\n    public:\n\
    \        modint() : x(0) {}\n        \n        modint(long long x) : x((x % mod\
    \ + mod) % mod) {}\n\n        modint& operator+=(modint p) {\n            x +=\
    \ p.x;\n            if (x >= mod) x -= mod;\n            return *this;\n     \
    \   }\n\n        modint& operator-=(modint p) {\n            x += mod - p.x;\n\
    \            if (x >= mod) x -= mod;\n            return *this;\n        }\n\n\
    \        modint& operator*=(modint p) {\n            x = (1LL * x * p.x % mod);\n\
    \            return *this;\n        }\n\n        modint& operator/=(modint p)\
    \ {\n            *this *= p.inv();\n            return *this;\n        }\n\n \
    \       modint operator-() const {\n            return modint(-x);\n        }\n\
    \n        modint operator+(const modint& p) const {\n            return modint(*this)\
    \ += p;\n        }\n\n        modint operator-(const modint& p) const {\n    \
    \        return modint(*this) -= p;\n        }\n\n        modint operator*(const\
    \ modint& p) const {\n            return modint(*this) *= p;\n        }\n\n  \
    \      modint operator/(const modint& p) const {\n            return modint(*this)\
    \ /= p;\n        }\n\n        long long val() {\n            return x;\n     \
    \   }\n\n        modint pow(long long p) {\n            modint res(1), val(x);\n\
    \            while(p) {\n                if (p & 1) res *= val;\n            \
    \    val *= val;\n                p >>= 1;\n            }\n            return\
    \ res;\n        }\n\n        modint inv() {\n            return pow(mod - 2);\n\
    \        }\n    };\n\n}// namespace zawa\n#line 5 \"test/gcd-convolution.test.cpp\"\
    \n\n#include <iostream>\n\nusing mint = zawa::modint<998244353>;\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<mint> as(n), bs(n);\n   \
    \ for (auto& a : as) {\n        int t;\n        std::cin >> t;\n        a = mint(t);\n\
    \    }\n    for (auto& b : bs) {\n        int t;\n        std::cin >> t;\n   \
    \     b = mint(t);\n    }\n    zawa::gcd_convolution<mint> conv(n);\n    auto\
    \ ans = conv.convolution(as, bs);\n    for (int i = 0 ; i < (int)(ans.size())\
    \ ; i++) {\n        std::cout << ans[i].val() << (i + 1 == (int)ans.size() ? '\\\
    n' : ' ');\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ \"../src/math/gcd-convolution.hpp\"\n#include \"../src/math/modint.hpp\"\n\n\
    #include <iostream>\n\nusing mint = zawa::modint<998244353>;\n\nint main() {\n\
    \    int n;\n    std::cin >> n;\n    std::vector<mint> as(n), bs(n);\n    for\
    \ (auto& a : as) {\n        int t;\n        std::cin >> t;\n        a = mint(t);\n\
    \    }\n    for (auto& b : bs) {\n        int t;\n        std::cin >> t;\n   \
    \     b = mint(t);\n    }\n    zawa::gcd_convolution<mint> conv(n);\n    auto\
    \ ans = conv.convolution(as, bs);\n    for (int i = 0 ; i < (int)(ans.size())\
    \ ; i++) {\n        std::cout << ans[i].val() << (i + 1 == (int)ans.size() ? '\\\
    n' : ' ');\n    }\n}\n"
  dependsOn:
  - src/math/gcd-convolution.hpp
  - src/math/prime-sieve.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/gcd-convolution.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 11:16:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/gcd-convolution.test.cpp
layout: document
redirect_from:
- /verify/test/gcd-convolution.test.cpp
- /verify/test/gcd-convolution.test.cpp.html
title: test/gcd-convolution.test.cpp
---
