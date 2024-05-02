// Binary search tree basic examples
#include <iostream>
#include <stack>

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
void tree_inorder_traversal_stack(tree_node<T> *t) {
    if (t == nullptr)
        return;

    std::stack<tree_node<T> *> S;
    tree_node<T> *current = t;

    while (current != nullptr || !S.empty()) {
        // Reach the leftmost node of the current subtree
        while (current != nullptr) {
            S.push(current);
            current = current->left;
        }
        // Pop the top node from the stack
        current = S.top();
        S.pop();
        // Process the popped node
        std::cout << current->key << '\n';
        // Move to the right subtree
        current = current->right;
    }
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
int depth(const tree_node<T> *t, const tree_node<T> *node) {
    if (t == nullptr || t == node)
        return 0;
    int left_depth = depth(t->left, node);
    int right_depth = depth(t->right, node);
    if (left_depth == -1 && right_depth == -1)
        return -1; // Node not found in the subtree rooted at root
    return 1 + std::max(left_depth, right_depth);
}

template<typename T>
int tree_max(tree_node<T> *t) {
    if (t == nullptr)
        throw std::exception();
    return std::max(t->key, std::max(tree_max(t->left), tree_max(t->right)));
}

template<typename T>
int tree_min(tree_node<T> *t) {
    if (t == nullptr)
        throw std::exception();
    return std::min(t->key, std::min(tree_min(t->left), tree_min(t->right)));
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

template<typename T>
void non_preorder_traversal(tree_node<T> *t) {
    if (t == nullptr)
        return;

    std::stack<tree_node<T> *> S;
    S.push(t);

    while (!S.empty()) {
        tree_node<T> *current = S.top();
        S.pop();
        std::cout << current->key << "\n";
        // Visit the right subtree before the left subtree
        if (current->right != nullptr)
            S.push(current->right);
        if (current->left != nullptr)
            S.push(current->left);
    }
}

template<typename T>
int right_wobbly(tree_node<T> *t, tree_node<T> *target) {
    if (t == nullptr || target == nullptr)
        return 0;

    int right_count = 0;
    int left_count = 0;

    tree_node<T> *current = t;

    // Traverse from root to the target node
    while (current != target) {
        if (current->key < target->key) {
            // Move to the right child
            right_count++;
            current = current->right;
        } else {
            // Move to the left child
            left_count++;
            current = current->left;
        }
    }
    // Return the right wobbly
    return right_count - left_count;
}

template<typename T>
int left_wobbly(tree_node<T> *t, tree_node<T> *target) {
    if (t == nullptr || target == nullptr)
        return 0;

    int right_count = 0;
    int left_count = 0;

    tree_node<T> *current = t;
    // Traverse from root to the target node
    while (current != target) {
        if (current->key > t) {
            // Move to the left child
            left_count++;
            current = current->left;
        } else {
            // Move to the right child
            right_count++;
            current = current->right;
        }
    }
    // Return the left wobbly
    return left_count - right_count;
}

template<typename T>
int thickness(tree_node<T> *t) {
    if (t == nullptr)
        return 0;
    std::stack<tree_node<T> *> S;
    S.push(t);
    int left, right, l, r;

    while (!S.empty()) {
        tree_node<T> *current = S.top();
        S.pop();
        r = right_wobbly(t, current);
        if (r > right) {
            right = r;
        }
        l = left_wobbly(t, current);
        if (l > left) {
            left = l;
        }
        std::cout << current->key << ":" << l << ":" << r << "\n";

        // Visit the right subtree before the left subtree
        if (current->right != nullptr)
            S.push(current->right);
        if (current->left != nullptr)
            S.push(current->left);
    }
    return left + right;
}