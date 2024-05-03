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
        std::cout << "reverse order ";
        while (back != nullptr) {
            std::cout << back->key << "->";
            back = back->prev;
        }
        std::cout << std::endl;
    }

    template<typename T>
    node<T> *push_front(node<T> *&front, const T &key) {
        node<T> *new_node = new node<T>{key, front->next, front};
        front->next->prev = new_node;
        front->next = new_node;
        return front;
    }

    template<typename T>
    node<T> *push_back(node<T> *&back, const T &key) {
        node<T> *new_node = new node<T>{key, back, back->prev};
        back->prev->next = new_node;
        back->prev = new_node;
        return new_node;
    }

    template<typename T>
    void append(node<T> *&tail, T key) {
        node<T> *new_node = new node<T>{key, tail, tail->prev};
        tail->prev->next = new_node;
        new_node->next = tail;
        tail->prev = new_node;
    }

    template<typename T>
    node<T> *insert_in_place(node<T> *&front, node<T> *&p) {
//        std::cout << "insert p=" << p->key << std::endl;
        // find out which node should insert behind it
        node<T> *target = p->prev;
        while (target != front and target->key > p->key) {
            target = target->prev;
        }
//        std::cout << "after target " << target->key << std::endl;
        node<T> *temp = p;
        node<T> *temp_left = p->prev;
        node<T> *temp_right = p->next;
        node<T> *target_right = target->next;
        if (p->key == target->next->key) {
            return front;
        } else {
//            std::cout << "1 " << p->key << ".next=" << target->next->key << std::endl;
            p->next = target->next;
        }
//        std::cout << "2 " << target->key << ".next=" << p->key << std::endl;
        target->next = p;
//        std::cout << "3 " << temp_left->key << ".next=" << temp_right->key << std::endl;
        temp_left->next = temp_right;
//        std::cout << "4 " << temp->key << ".prev=" << target->key << std::endl;
        temp->prev = target;
//        std::cout << "5 " << target_right->key << ".prev=" << temp->key << std::endl;
        target_right->prev = temp;
//        std::cout << "6 " << temp_right->key << ".prev=" << temp_left->key << std::endl;
        temp_right->prev = temp_left;
        return front;
    }

    template<typename T>
    void insertion_sort(node<T> *&front, node<T> *&end) {
        if (front == end || front == nullptr || end == nullptr) {
            return;
        }

        for (auto i = front->next->next; i != end; i = i->next) {
//            std::cout << "i=" << i->key << std::endl;
            insert_in_place(front, i);
        }
    }
}


#define PRACTICE_DOUBE_LINK_LIST_H

#endif //PRACTICE_DOUBE_LINK_LIST_H
