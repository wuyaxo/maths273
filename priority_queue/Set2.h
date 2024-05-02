//
// Created by David on 4/18/24.
//
#include <iostream>
#include <treap_node>
#ifndef PRIORITY_QUEUE_SET2_H
template<typename T>
class Set{
public:
    Set();
    ~Set();
    size_t size() const;
    void print() const;
    void insert(const T&);
    void remove(const T&);

private:
    treap_node<T> *;
};
#define PRIORITY_QUEUE_SET2_H

#endif //PRIORITY_QUEUE_SET2_H
