//
// Created by David on 3/21/24.
//
#include <iostream>
#include <vector>
#include <exception>

template<typename T>
T min(const std::vector<T> &nums) {
    T temp;
    if (nums.empty()) {
        throw std::exception();
    }
    for (auto it: nums) {
        if (it < temp) {
            temp = it;
        }
    }
    return temp;
}

int main() {
    std::vector<int> nums;
    std::cout << min(nums);
    return 0;
}