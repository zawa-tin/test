#pragma once

#include <iostream>
#include <utility>
#include <vector>

namespace zawa::input {

template <typename T> 
void in(T& res) { std::cin >> res; }

template <typename Head, typename... Tail>
void in(Head& head, Tail&... tail) { in(head); in(tail...); }

template <typename T, typename U>
void in(std::pair<T, U>& res) { in(res.first); in(res.second); }

template <typename T>
void in(std::vector<T>& res) { for (auto& r : res) { in(r); } }

} // namespace zawa::input
