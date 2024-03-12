// Binary search tree basic examples
#include <iostream>
//#include <random>

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
bool tree_research(const tree_node<T> *t, const T &key) {
    if (t == nullptr) return false;
    if (t->key == key) {
        return true;
    } else {
        return tree_research(t->left, key) or tree_research(t->right, key);
    }
}


int main() {
    tree_node<int> *my_tree = nullptr; // empty tree

    // insert random data into the tree
    for (auto n: {5, 3, 7, 20, 10, 8, 4, 1}) {
        tree_insert(my_tree, n);
    }

//    tree_inorder_traversal(my_tree);
    std::cout << "The height of the BST is:" << tree_height(my_tree) << std::endl;
    std::cout << "The size of the BST is:" << size(my_tree) << std::endl;
    std::cout << "search '1' in the BST:" << tree_research(my_tree, 1) << std::endl;
    std::cout << "search '2' in the BST:" << tree_research(my_tree, 2) << std::endl;
}