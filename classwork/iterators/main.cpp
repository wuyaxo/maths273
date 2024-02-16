#include <iostream>

int main() {
    std::vector<int> nums = {10,8,6,4,2,0};

//    for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
//        std::cout << *i << std::endl;
//    }

    std::sort(nums.begin(),nums.begin()+2);
    for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
        std::cout << *i << std::endl;
    }
//    std::cout << "visit in reverse" << std::endl;
//    for (std::vector<int>::reverse_iterator i = nums.rbegin(); i != nums.rend(); i++) {
//        std::cout << *i << std::endl;
//    }
    return 0;
}
