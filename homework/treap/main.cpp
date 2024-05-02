#include <iostream>
#include "treap.hpp"

int main() {

    treap_node<int, int> *root = nullptr;

    // Insertion example
    root = insert(root, 4, rand());
    root = insert(root, 2, rand());
//    root = insert(root, 6, rand());
//    root = insert(root, 1, rand());
//    root = insert(root, 3, rand());
//    root = insert(root, 5, rand());
//    root = insert(root, 7, rand());

    cout << "Inorder traversal after insertion: ";
    inorderTraversal(root);
    cout << endl;

    // Deletion example
    root = deleteNode(root, 4);

    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
