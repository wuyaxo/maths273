//
// Created by David on 4/29/24.
//
#include <random>

#ifndef PRACTICE_SORT_HELPER_H

namespace sortHelper {
    int *generateRandomNumber(int size, int rangeL, int rangeR) {
        int *arr = new int[size];
        std::mt19937 e;
        std::uniform_int_distribution<int> u(rangeL, rangeR);
        for (int i = 0; i < size; i++) {
            arr[i] = u(e);
        }
        return arr;
    }
}
#define PRACTICE_SORT_HELPER_H

#endif //PRACTICE_SORT_HELPER_H
