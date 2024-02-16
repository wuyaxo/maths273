#include <iostream>
#include <random>
#include <chrono>
#include "gcd.h"


void test(int m, int n) {
    std::chrono::steady_clock clock;
    auto tp1 = clock.now();
    int gcd1 = gcd_instructor(m, n);
    auto tp2 = clock.now();
    int gcd2 = gcd_modulus(m, n);
    auto tp3 = clock.now();
    auto diff_time1 = tp2 - tp1;
    auto diff_time2 = tp3 - tp2;
    auto t1 = std::chrono::duration_cast<std::chrono::nanoseconds>(diff_time1).count();
    auto t2 = std::chrono::duration_cast<std::chrono::nanoseconds>(diff_time2).count();
    std::cout << "m=" << m << ",n=" << n << ",gcd=" << gcd1 << ",t1=" << t1 << ",t2=" << t2 << std::endl;
}

int main() {
    std::mt19937 e;
    std::uniform_int_distribution<int> u(10, 99999);
    for (int i = 0; i < 10; i++) {
        int m = u(e);
        int n = u(e);
        test(m, n);
    }
    return 0;
}


