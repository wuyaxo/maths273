//
// Created by David on 2/27/24.
//

#include <iostream>
#include "stack.hpp"

int main() {
//    stack<int, 64> stackA;
//    stackA.push(1);
//    stackA.push(3);
//    stackA.push(5);
//    stackA.push(7);
//    stackA.push(9);
//    std::cout << "stack top is :" << stackA.top() << std::endl;
//    std::cout << "stack size is :" << stackA.size() << std::endl;
//    stackA.pop();
//    std::cout << "stack top is :" << stackA.top() << std::endl;
//    std::cout << "stack size is :" << stackA.size() << std::endl;
//    while (stackA.size()>0){
//        stackA.pop();
//    }
//    stackA.pop();
//    std::cout << "stack top is :" << stackA.top() << std::endl;

    stack<int, 5> s; // small capacity to test overflow/underflow
    for (int n: {1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        s.push(n);
    }
    // empty the stack
    do {
        std::cout << "Top is now: " << s.top() << '\n';
        s.pop();
    } while (s.size() > 0);
    s.pop(); // try to pop empty stack
    std::cout << s.top(); //
    return 0;
}
