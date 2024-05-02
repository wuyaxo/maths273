//
// Created by David on 3/21/24.
//
#include <iostream>

void print(int m, int n) {
    std::cout << m << ",";
    if (m == n) {
        return;
    } else if (m < n) {
        print(m + 1, n);
    } else {
        print(m - 1, n);
    }
}

int main() {
    print(6,0);
}