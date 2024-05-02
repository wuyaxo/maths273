//
// Created by David on 4/30/24.
//
#include <iostream>

#ifndef PRACTICE_DOUBE_LINK_LIST_H
namespace dll {
    template<typename T>
    struct node {
        T key;
        node *next = nullptr;
        node *prev = nullptr;
    };


    template<typename T>
    void list_print(node<T> *n) {
        for (auto i = n; i != nullptr; i = i->next) {
            std::cout << i->key << '\t';
        }
        std::cout << std::endl;
    }

    template<typename T>
    void reverse_print(node<T> *back) {
        while (back != nullptr) {
            std::cout << back->key << "\t";
            back = back->prev;
        }
        std::cout << std::endl;
    }

    template<typename T>
    node<T> *push_front(node<T> *&front, const T &key) {
        node<T> *new_node = new node<T>{key, front->next, front};
        front->next->prev = new_node;
        front->next = new_node;
        return new_node;
    }

    template<typename T>
    node<T> *push_back(node<T> *&back, const T &key) {
        node<T> *new_node = new node<T>{key, back, back->prev};
        back->prev->next = new_node;
        back->prev = new_node;
    }

    template<typename T>
    node<T> *insert_in_place(node<T> *&front, node<T> *&p) {
        node<T> *&back = front->next;
        while (back->next != nullptr) {
            back = back->next;
        }

        // find out which node should insert behind it
        dll::node<int> *ptr = back->prev;
        while (ptr->prev != front and ptr->key > p->key) {
            ptr = ptr->prev;
        }

        ptr->next->prev = p;
        p->next = ptr->next;
        ptr->next = p;
        p->prev = ptr;
    }
}

#define PRACTICE_DOUBE_LINK_LIST_H

#endif //PRACTICE_DOUBE_LINK_LIST_H
