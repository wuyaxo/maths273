#include <iostream>
#include <string>
#include "postfix.hpp"


int main() {
//    std::string input{"2 4 -"};
//    int res = postfix_calculator(input);
//    std::cout << res << std::endl;
//    input = {"2 3 4 5 + - *"}; // (4+5), 3-(9), 2*(-6)
//    res = postfix_calculator(input);
//    std::cout << res << std::endl;
//    input = {"2 5 + 3 7 - -"}; // (2+5), (3-7), (2+5)-(3-7)
//    res = postfix_calculator(input);
//    std::cout << res << std::endl;
//    std::string expr = "* + 3 4 5"; // equivalent to (3 + 4) * 5 = 35
//    std::cout << "Result: " << prefix_calculator(expr) << std::endl;

    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    reverse(stack);
    std::cout << std::endl;
}
