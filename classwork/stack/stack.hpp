#include <iostream>


template<typename T, int CAPACITY>
class stack {
public:
    void push(const T &);

    void pop();

    T &top();

    size_t size() const;

private:
    T storage[CAPACITY];
    int top_index = 0;
    const int capacity = CAPACITY;
};

template<typename T, int CAPACITY>
void stack<T, CAPACITY>::push(const T &x) {
    storage[top_index] = x;
    top_index++;
}

template<typename T, int CAPACITY>
void stack<T, CAPACITY>::pop() {
    if (top_index > 0) top_index--;
}

template<typename T, int CAPACITY>
size_t stack<T, CAPACITY>::size() const {
    return top_index;
}

template<typename T, int CAPACITY>
T &stack<T, CAPACITY>::top() {
    if (top_index == 0) return storage[0];
    return storage[top_index - 1];
}
