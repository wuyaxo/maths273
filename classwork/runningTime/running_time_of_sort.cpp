// Created by David on 2/22/24.
#include <iostream>
#include <random>
#include "timer.h"

void doSort(int n) {
    std::mt19937 e;
    std::uniform_int_distribution<int> u;
    std::vector<int> nums(n);

    for (auto &i: nums) {
        i = u(e);
    }
    timer<std::chrono::milliseconds> my_time;
    my_time.start();
    std::sort(nums.begin(), nums.end());
    my_time.end();
    std::cout << n << "\t\t" << my_time.count() << std::endl;
}


int main() {
    std::cout << "size (n)" << "\t\t" << "running time (ms)" << std::endl;
    std::vector<int> sizes(10);
    for (int i = 1; i <= 10; i++) {
        doSort(i * 1000000);
    }
    return 0;
}
