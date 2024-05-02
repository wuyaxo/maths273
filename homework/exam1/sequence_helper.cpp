#include <iostream>

unsigned long int x(unsigned long int n) {
    if (n == 0) return 1;
    else if (n == 1) return 2;
    else if (n == 2) return 3;
    else return x(n - 1) + x(n - 2) + x(n - 3);
}

unsigned long int x_helper(unsigned long int n) {
    if (n == 0) return 1;
    else if (n == 1) return 2;
    else if (n == 2) return 3;
    unsigned long int zero = 1, first = 2, second = 3;
    unsigned long int third = zero + first + second;
    while (n > 3) {
        unsigned long int old_zero = zero, old_first = first, old_second = second;
        zero = old_first;
        first = old_second;
        second = old_zero + old_first + old_second;
        third = zero + first + second;
        n--;
    }
    return third;
}

unsigned long int x_helper1(unsigned long int n, unsigned long int a, unsigned long int b, unsigned long int c) {
    if (n == 0) return a;
    else if (n == 1) return b;
    else if (n == 2) return c;
    return x_helper1(n - 1, b, c, a + b + c);
}

unsigned long int x1(unsigned long int n) {
    return x_helper1(n,1,2,3);
}

int main() {
//    std::cout << x(3) << std::endl;
    std::cout << x1(50) << std::endl;
    return 0;
}
