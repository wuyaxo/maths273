//
// Created by David on 2/7/24.
//

#include <stdexcept>
#include "gcd.h"

int gcd_instructor(int a, int b) {
    if (a < 0 || b < 0) {
        throw std::invalid_argument("Parameters must be positive integers");
    }
    if (a == b)
        return a;
    if (a > b)
        return gcd_instructor(a - b, b);
    else
        return gcd_instructor(a, b - a);
}

int gcd_modulus(int a, int b) {
    if (a < 0 || b < 0) {
        throw std::invalid_argument("Parameters must be positive integers");
    }
    if (b == 0) {
        return a;
    }
    if (a > b) {
        return gcd_modulus(b, a % b);
    } else {
        return gcd_modulus(a, b % a);
    }

}