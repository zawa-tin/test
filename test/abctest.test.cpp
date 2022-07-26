#define PROBLEM "https://atcoder.jp/contests/abc248/tasks/abc248_a"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    int t = 0;
    for (int i = 0 ; i < 10 ; i++) t = (t xor i);
    for (auto c : s) t = (t xor (c - '0'));
    cout << t << endl;
}

