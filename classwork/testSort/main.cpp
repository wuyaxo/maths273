#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
#include "timer.h"


int main() {
    std::mt19937 e;
    std::uniform_int_distribution<int> u;
    std::vector<int> nums(1000000);

    for (auto &n: nums) {
        n = u(e);
    }
    timer<std::chrono::milliseconds> my_time;
    my_time.start();
    std::sort(nums.begin(), nums.end());
    my_time.end();
    std::cout << my_time.count() << std::endl;
    return 0;
}
