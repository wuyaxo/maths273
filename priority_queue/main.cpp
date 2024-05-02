#include <iostream>

#include "Set.hpp"

int main() {
    Set X = {1, 2, 3, 4};
    Set B = {1, 4, 5};
//    X ^= B;
    X.print();
//    std::cout << "size: " << X.size();
//    std::cout << "contains: " << X.contains(5) << std::endl;
//    std::cout << "contains: " << X.contains(B) << std::endl;
    std::cout << "contains: " << B.subset(X) << std::endl;
    return 0;
}
