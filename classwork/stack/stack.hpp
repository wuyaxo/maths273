#include <iostream>
#include <exception>

#pragma once

template<typename T, int CAPACITY>
class stack {
public:
    void push(const T &);

    void pop();

    T &top();

    [[nodiscard]] size_t size() const;

private:
    T storage[CAPACITY];
    int top_index = -1;
//    const int capacity = CAPACITY;
};

template<typename T, int CAPACITY>
void stack<T, CAPACITY>::push(const T &x) {
    storage[top_index] = x;
    top_index++;
}

template<typename T, int CAPACITY>
void stack<T, CAPACITY>::pop() {
    if (top_index < 0) {
        throw std::out_of_range("Empty stack can not execute pop()");
    } else {
        top_index--;
    }
}

template<typename T, int CAPACITY>
size_t stack<T, CAPACITY>::size() const {
    return top_index + 1;
}

template<typename T, int CAPACITY>
T &stack<T, CAPACITY>::top() {
    if (top_index == -1) {
        throw std::underflow_error("Empty stack has no data to display");
    }
    return storage[top_index - 1];
}
