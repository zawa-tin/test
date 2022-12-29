#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_C"

#include "../src/template/input.hpp"
using namespace zawa::input;

#include "../src/template/output.hpp"
using namespace zawa::output;

#include <set>
#include <string>

int main() {
    int n;
    in(n);
    std::set<std::string> st;
    for (int _ = 0 ; _ < n ; _++) {
        std::string q, s; in(q, s);
        if (q[0] == 'i') {
            st.insert(s);
        }
        else {
            yesno(st.count(s), "yes", "no"); 
        }
    }
}
