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


    for (int i = 0; i < 4; i++) {
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
//    insertion_sort(front, back);
    list_print(front);
//    reverse_print(back);

//    auto copy_front = new dll::node<int>{}; //fake node
//    auto copy_back = new dll::node<int>{}; //fake node
//    dll::node<int> *copy = new dll::node<int>{front->next->key, copy_back, copy_front};
//    copy_front->next = copy;
//    copy_back->prev = copy;
//
//    for (auto i = front->next->next; i->next != nullptr; i = i->next) {
//        dll::append(copy_back, i->key);
//    }


//    auto new_front = new dll::node<int>{};
//    auto new_back = new dll::node<int>{};
//    dll::node<int> *sorted_list = new dll::node<int>{front->next->key, new_back, new_front};
//    new_front->next = sorted_list;
//    new_back->prev = sorted_list;


//    front = insert_in_place(front, front->next->next);
//    list_print(front);
//    reverse_print(back);
//
//    insert_in_place(front, front->next->next);
//    list_print(front);
//    reverse_print(back);
//
//    insert_in_place(front, front->next->next->next);
//    list_print(front);
//    reverse_print(back);
//
//    insert_in_place(front, front->next->next->next->next);
//    list_print(front);
//    reverse_print(back);
//
//    insert_in_place(front, front->next->next->next->next->next);
//    list_print(front);
//    reverse_print(back);

//
//    insert_in_place(front, front->next->next->next->next->next);
//    list_print(front);
//    reverse_print(back);



    insertion_sort(front, back);
    list_print(front);
    reverse_print(back);


//    insert_in_place(front, front->next->next->next);
//    list_print(new_front);
}
