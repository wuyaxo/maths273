//
// Created by David on 3/20/24.
//

#include <iostream>

bool isLastNumberEquals3(int num) {
    int temp = std::abs(num);
    if (temp - 3 == (temp / 10) * 10)
        return true;
    else
        return false;
}


int num3s(int n) {
    if (n == 0) return 0;
    else {
        return num3s(n / 10) + (n % 10 == 3 ? 1 : 0);
    }
}

int num_threes_in_range(int m, int n) {
    if (m == n) return num3s(m);
    else {
        return num3s(m) + num_threes_in_range(m + 1, n);
    }
}

int main() {
    std::cout << num_threes_in_range(20, 35) << std::endl; //8
    return 0;
}