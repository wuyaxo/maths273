#include <iostream>

template<typename T>
struct node {
    T key;
    node *next = nullptr;
};

template<typename T>
void list_print(node<T> *front) {
    for (auto i = front; i != nullptr; i = i->next) {
        std::cout << i->key << '\t';
    }
    std::cout << std::endl;
}

template<typename K>
void list_insert_before_front(node<K> *&list, const K &key) {
    auto new_front = new node<K>{key, list};
    list = new_front;
}

template<typename T>
void list_insert_after_back(node<T> *&list, const T &key) {
    if (list == nullptr) {
        list = new node<T>{key};
        return;
    }
    node<T> *ptr = list;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    auto new_back = new node<T>{key};
    ptr->next = new_back;
}

template<typename T>
void list_remove_front(node<T> *&list) {
    if (list == nullptr) {
        return;
    }
    auto old_front = list;
    list = list->next;
    delete old_front;
}

template<typename T>
void list_remove_back(node<T> *&list) {
    if (list == nullptr) {
        return;
    }
    //recite the last ptr to remove
    node<T> *ptr = list;
    while (ptr->next->next != nullptr) {
        //recite the second-last ptr in order to set the next node to nullptr
        ptr = ptr->next;
    }
    //remove garbage
    delete ptr->next->next;
    //disconnect link
    ptr->next = nullptr;
}

template<typename T>
int list_size(node<T> *&list) {
    auto ptr = list;
    int count = 1;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

template<typename T>
T list_nth(node<T> *&list, int n) {
    auto ptr = list;
    for (int i = 0; i < n; i++) {
        ptr = ptr->next;
        if (ptr == nullptr) {
            return 0;
        }
    }
    return ptr->key;
}

template<typename T>
void list_remove_after(node<T> *&list, node<T> *&target) {
    auto ptr = list;
    while (ptr->next != target) {
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = nullptr;
}


int main() {
    node<char> *my_list = nullptr; // empty list
    list_insert_before_front(my_list, 'd');
    list_insert_before_front(my_list, 'c');
    list_insert_before_front(my_list, 'b');
    list_insert_after_back(my_list, 'a');

//    my_list->next->next->next = my_list->next->next;
//    std::cout << my_list->next->next->next->next->key;


    list_print(my_list);
//    list_remove_front(my_list)
//    list_print(my_list);
//    list_remove_back(my_list);
//    list_print(my_list);
//    list_insert_after_back(my_list, 'd');
//    list_print(my_list);
    auto target = my_list->next->next;
    list_print(target);
    list_remove_after(my_list, target);
    list_print(my_list);
}
