#include <iostream>
#include <cstdlib>

using namespace std;

template<typename K, typename P>
struct treap_node {
    K key;
    P priority;
    treap_node *left = nullptr, *right = nullptr;
};

// Function to rotate a node to the left
template<typename K, typename P>
treap_node<K, P> *rotateLeft(treap_node<K, P> *x) {
    treap_node<K, P> *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Function to rotate a node to the right
template<typename K, typename P>
treap_node<K, P> *rotateRight(treap_node<K, P> *y) {
    treap_node<K, P> *x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

// Function to insert a key into the treap
template<typename K, typename P>
treap_node<K, P> *insert(treap_node<K, P> *t, int key, int priority) {
    if (t == nullptr) {
        treap_node<K, P> *node = new treap_node<K, P>;
        node->key = key;
        node->priority = priority;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

    if (key <= t->key) {
        t->left = insert(t->left, key, priority);
        // Rotate right if the priority of the new node is greater than the priority of the t
        if (t->left->priority > t->priority)
            t = rotateRight(t);
    } else {
        t->right = insert(t->right, key, priority);
        // Rotate left if the priority of the new node is greater than the priority of the t
        if (t->right->priority > t->priority)
            t = rotateLeft(t);
    }

    return t;
}

// Function to find the node with the maximum key in the treap
template<typename K, typename P>
treap_node<K, P> *findMax(treap_node<K, P> *t) {
    if (t == nullptr)
        return nullptr;
    while (t->right != nullptr)
        t = t->right;
    return t;
}

// Function to delete a key from the treap
template<typename K, typename P>
treap_node<K, P> *deleteNode(treap_node<K, P> *t, int key) {
    if (t == nullptr)
        return nullptr;

    if (key < t->key)
        t->left = deleteNode(t->left, key);
    else if (key > t->key)
        t->right = deleteNode(t->right, key);
    else {
        if (t->left == nullptr) {
            treap_node<K, P> *temp = t->right;
            delete t;
            return temp;
        } else if (t->right == nullptr) {
            treap_node<K, P> *temp = t->left;
            delete t;
            return temp;
        } else {
            // treap_node with two children
            if (t->left->priority < t->right->priority) {
                t = rotateLeft(t);
                t->left = deleteNode(t->left, key);
            } else {
                t = rotateRight(t);
                t->right = deleteNode(t->right, key);
            }
        }
    }

    return t;
}

// Function to print the inorder traversal of the treap
template<typename K, typename P>
void inorderTraversal(treap_node<K, P> *t) {
    if (t == nullptr)
        return;
    inorderTraversal(t->left);
    cout << "(" << t->key << "," << t->priority << ") ";
    inorderTraversal(t->right);
}
