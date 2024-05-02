#include <iostream>
#include <random>
#include "double_link_list.h"


int main() {

    auto front = new dll::node<int>{}; //fake node
    auto back = new dll::node<int>{}; //fake node
    std::mt19937 e;
    std::uniform_int_distribution<int> u(1, 99);

    dll::node<int> *my_list = new dll::node<int>{100, back, front};
    front->next = my_list;
    back->prev = my_list;


    for (int i = 0; i < 10; i++) {
        push_front(my_list, u(e));
    }


/**
    dll::node<int> *new_node = new dll::node<int>{5, nullptr, nullptr};
    // find out which node should insert behind it
    dll::node<int> *ptr = back->prev;
    while (ptr->prev != front and ptr->key > new_node->key) {
        ptr = ptr->prev;
    }


    ptr->next->prev = new_node;
    new_node->next = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
**/
    //test
    list_print(front);
//    reverse_print(back);
    insert_in_place(front, front->next->next);
    list_print(front);
//
//    for (auto i = front->next->next; i != nullptr; i = i->next) {
//
//    }


}
