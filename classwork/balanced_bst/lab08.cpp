#include <iostream>
#include <random>
#include <cmath>
#include "bst.hpp"

int main() {

    std::mt19937 e;
    std::uniform_int_distribution<int> u;
    tree_node<int> *my_tree = nullptr;

//    std::cout << "size\theight\tratio" << std::endl;
//    for (int i = 1; i <= 10; i++) {
//        for (int j = 0; j < 100000; j++) {
//            int num = u(e);
//            tree_insert(my_tree, num);
//        }
//        int height = tree_height(my_tree);
//        std::cout << i * 100000 << "\t" << height << "\t" << i * 100000.0 / log2(height)
//                  << std::endl;
//    }


    for (auto n: {5, 3, 7, 20, 10, 8, 4, 1}) {
        tree_insert(my_tree, n);
    }

//    tree_node<int> *target = my_tree->left;

    std::cout << tree_max(my_tree);
    return 0;
}
