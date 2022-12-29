#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace zawa::output {

void out() { 
    std::cout << std::endl; 
}

template <class T>
void out(const T& a) { 
    std::cout << a << std::endl; 
}

template <class T>
void out(const std::vector<T>& as) { 
    for (std::size_t i = 0 ; i < as.size() ; i++) { 
        std::cout << as[i] << (i + 1 == as.size() ? '\n' : ' '); 
    } 
}

template <class Head, class... Tail>
void out(const Head& head, const Tail&... tail) { 
    std::cout << head; 
    if (sizeof...(tail)) { 
        std::cout << ' '; 
    } 
    out(tail...);
}

void yesno(bool flag, std::string yes = "Yes", std::string no = "No") {
    std::cout << (flag ? yes : no) << std::endl;
}

} // namespace zawa::output
