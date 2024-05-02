#include <iostream>
#include <random>
#include <cmath>
#include "timer.h"
#include "merge_sort.h"


void verifyMergeSort(std::vector<int> &nums) {
    merge_sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << "\t";
    }
    std::cout << std::endl;
}

void compare_sort_speed(int n) {
    std::mt19937 e;
    std::uniform_int_distribution<int> u;
    std::vector<int> nums(n);
    std::vector<int> temp(n);

    for (auto &i: nums) {
        i = u(e);
    }
    std::vector<int> nums2 = nums;
    timer<std::chrono::milliseconds> my_time;

    my_time.start();
    std::sort(nums2.begin(), nums2.end());
    my_time.end();
    std::cout << "std::sort cost:" << my_time.count() << " milliseconds\n";

    my_time.start();
    merge_sort(nums.begin(), nums.end());
    my_time.end();
    std::cout << "merge sort cost:" << my_time.count() << " milliseconds\n";
}


void doMergeSort(int n) {
    std::mt19937 e;
    std::uniform_int_distribution<int> u;
    std::vector<int> nums(n);
    std::vector<int> temp(n);

    for (auto &i: nums) {
        i = u(e);
    }
    timer<std::chrono::milliseconds> my_time;
    my_time.start();
    merge_sort(nums.begin(), nums.end());
    my_time.end();
    std::cout << n << "\t" << my_time.count() << "\t" << my_time.count() / (n * log2(n)) << std::endl;
}


int main() {
    //(1) verify that it sorts correctly
    std::vector<int> nums{2, 1, 7, 10, 3, 9, 8, 5, 6, 4};
    verifyMergeSort(nums);// expert 1,2,3,4,5,6,7,8,9,10
    //(2) verify that it is slower than std::sort
    compare_sort_speed(1000000);
    //(3) verify that it has complexity O(n*log(n)) (experimentally).
    std::cout << "size (n)" << "\trunning time (ms)" << "\t constant" << std::endl;
    std::vector<int> sizes(10);
    for (int i = 1; i <= 10; i++) {
        doMergeSort(i * 1000000);
    }
    return 0;
}

