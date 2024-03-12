#include <iostream>
#include <string>
#include "postfix.h"


int main() {
    std::string input{"2 4 -"};
    int res = postfix_calculator(input);
    std::cout << res << std::endl;
    input = {"2 3 4 5 + - *"};
    res = postfix_calculator(input);
    std::cout << res << std::endl;
    input = {"2 5 + 3 7 - -"};
    res = postfix_calculator(input);
    std::cout << res << std::endl;
    return 0;
}
