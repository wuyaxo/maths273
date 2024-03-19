// Binary search tree basic examples
#include <iostream>

template<typename T>
struct tree_node {
    T key;
    tree_node *left = nullptr, *right = nullptr;
};

template<typename T>
void tree_insert(tree_node<T> *&t, const T &key) {
    if (t == nullptr) {
        t = new tree_node<T>{key};
        return;
    }
    if (key < t->key) tree_insert(t->left, key);
    else tree_insert(t->right, key);
}

template<typename T>
void tree_inorder_traversal(const tree_node<T> *t) {
    if (t == nullptr) return;
    tree_inorder_traversal(t->left);
    std::cout << t->key << '\n';
    tree_inorder_traversal(t->right);
}

template<typename T>
int tree_height(const tree_node<T> *t) {
    if (t == nullptr) return -1;
    return 1 + std::max(tree_height(t->left), tree_height(t->right));

}

template<typename T>
int size(const tree_node<T> *t) {
    if (t == nullptr) return 0;
    return 1 + size(t->left) + size(t->right);

}

template<typename T>
bool tree_search(const tree_node<T> *t, const T &key) {
    if (t == nullptr) return false;
    if (t->key == key) {
        return true;
    } else {
        return tree_search(t->left, key) or tree_search(t->right, key);
    }
}