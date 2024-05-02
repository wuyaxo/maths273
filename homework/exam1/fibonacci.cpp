//
// Created by David on 3/20/24.
//
#include <iostream>

template<typename T>
T fib(T n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n > 1) {
        return fib(n - 1) + fib(n - 2);
    } else if (n < 0) {
        return fib(n + 2) - fib(n + 1);
    }
}

int main() {

    std::cout << fib(-3) << "\t";
    std::cout << fib(-2) << "\t";
    std::cout << fib(-1) << "\t";
    std::cout << fib(0) << "\t";
    std::cout << fib(1) << "\t";
    std::cout << fib(2) << "\t";
    std::cout << fib(3) << std::endl;
}