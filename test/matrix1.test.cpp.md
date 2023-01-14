---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/matrix.hpp
    title: "matrix (\u884C\u5217)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/dp/submissions/38023510
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/matrix1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/matrix.hpp\"\n\n#include <vector>\n\nnamespace zawa {\n\
    \ntemplate <class T = long long>\nclass matrix {\nprivate:\n\tstd::vector<std::vector<T>>\
    \ dat;\n\npublic:\n\tstd::size_t r, c;\n\n\tmatrix(const std::vector<T>& dat)\
    \ : dat(dat), r(dat.size()), c(dat[0].size())  {}\n\tmatrix(std::size_t r, std::size_t\
    \ c) : dat(r, std::vector<T>(c)), r(r), c(c) {}\n\tmatrix(const matrix<T>& mat)\
    \ : dat(mat.r, std::vector<T>(mat.c)), r(mat.r), c(mat.c) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < c ; j++) {\n\t\t\t\
    \tdat[i][j] = mat[i][j];\n\t\t\t}\n\t\t}\t\n\t}\n\n\tstd::vector<T>& operator[](std::size_t\
    \ i) {\n\t\treturn dat[i];\n\t}\n\tconst std::vector<T>& operator[](std::size_t\
    \ i) const {\n\t\treturn dat[i];\n\t}\n\n\tmatrix& operator+=(const matrix<T>&\
    \ mat) {\n\t\tfor (std::size_t i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t\
    \ j = 0 ; j < c ; j++) {\n\t\t\t\tdat[i][j] += mat[i][j];\n\t\t\t}\n\t\t}\n\t\t\
    return *this;\n\t}\n\tmatrix operator+(const matrix<T>& mat) {\n\t\treturn matrix(*this)\
    \ += mat;\n\t}\n\n\tmatrix& operator-=(const matrix<T>& mat) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < c ; j++) {\n\t\t\t\
    \tdat[i][j] -= mat[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\tmatrix& operator-(const\
    \ matrix<T>& mat) {\n\t\treturn matrix(*this) -= mat;\t\n\t}\n\n\tmatrix operator*(const\
    \ matrix<T>& mat) {\n\t\tmatrix res(r, mat.c);\n\t\tfor (std::size_t i = 0 ; i\
    \ < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < mat.c ; j++) {\n\t\t\t\tfor\
    \ (std::size_t k = 0 ; k < r ; k++) {\n\t\t\t\t\tres[i][j] += dat[i][k] * mat[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tmatrix operator*=(const matrix<T>&\
    \ mat) {\n\t\treturn (*this) = (*this) * mat;\n\t}\n\n\tmatrix pow(long long p);\n\
    };\n\ntemplate <class T>\nmatrix<T> id_mul(std::size_t n) {\n\tmatrix<T> res(n,\
    \ n);\n\tfor (std::size_t i = 0 ; i < n ; i++) {\n\t\tres[i][i] = 1;\n\t}\n\t\
    return res;\n}\n\ntemplate <class T>\nmatrix<T> matrix<T>::pow(long long p) {\n\
    \tmatrix<T> res = id_mul<T>(this->r);\n\tmatrix<T> base(*this);\n\twhile (p >\
    \ 0) {\n\t\tif (p & 1) {\n\t\t\tres *= base;\n\t\t}\n\t\tbase *= base;\n\t\tp\
    \ >>= 1;\n\t}\n\treturn res;\n}\n\n} // namespace zawa\n#line 1 \"src/math/modint.hpp\"\
    \nnamespace zawa {\n\n    template<long long mod>\n    class modint {\n    private:\n\
    \        long long x;\n\n    public:\n        modint() : x(0) {}\n        \n \
    \       modint(long long x) : x((x % mod + mod) % mod) {}\n\n        modint& operator+=(modint\
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
    \ - 2);\n        }\n    };\n\n}// namespace zawa\n#line 5 \"test/matrix1.test.cpp\"\
    \n\n// using mint = zawa::modint<1000000007>;\n// using mat = zawa::matrix<mint>;\n\
    \n#include <iostream>\n\nint main() {\n\t// int n; std::cin >> n;\n\t// long long\
    \ k; std::cin >> k;\n\t// mat G(n, n);\n\t// for (int i = 0 ; i < n ; i++) {\n\
    \t// \tfor (int j = 0 ; j < n ; j++) {\n\t// \t\tint p; std::cin >> p;\n\t// \t\
    \tG[i][j] = p;\n\t// \t}\n\t// }\n\t// G = G.pow(k);\n\t// mint ans;\n\t// for\
    \ (int i = 0 ; i < n ; i++) {\n\t// \tfor (int j = 0 ; j < n ; j++) {\n\t// \t\
    \tans += G[i][j];\n\t// \t}\n\t// }\n\t// std::cout << ans.val() << std::endl;\n\
    \tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * Educational DP Contest\
    \ - R Walk\n * https://atcoder.jp/contests/dp/submissions/38023510\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/matrix.hpp\"\n#include \"../src/math/modint.hpp\"\n\
    \n// using mint = zawa::modint<1000000007>;\n// using mat = zawa::matrix<mint>;\n\
    \n#include <iostream>\n\nint main() {\n\t// int n; std::cin >> n;\n\t// long long\
    \ k; std::cin >> k;\n\t// mat G(n, n);\n\t// for (int i = 0 ; i < n ; i++) {\n\
    \t// \tfor (int j = 0 ; j < n ; j++) {\n\t// \t\tint p; std::cin >> p;\n\t// \t\
    \tG[i][j] = p;\n\t// \t}\n\t// }\n\t// G = G.pow(k);\n\t// mint ans;\n\t// for\
    \ (int i = 0 ; i < n ; i++) {\n\t// \tfor (int j = 0 ; j < n ; j++) {\n\t// \t\
    \tans += G[i][j];\n\t// \t}\n\t// }\n\t// std::cout << ans.val() << std::endl;\n\
    \tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * Educational DP Contest\
    \ - R Walk\n * https://atcoder.jp/contests/dp/submissions/38023510\n */\n"
  dependsOn:
  - src/math/matrix.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/matrix1.test.cpp
  requiredBy: []
  timestamp: '2023-01-15 01:17:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matrix1.test.cpp
layout: document
redirect_from:
- /verify/test/matrix1.test.cpp
- /verify/test/matrix1.test.cpp.html
title: test/matrix1.test.cpp
---
