//
// Created by David on 4/16/24.
//
#include <initializer_list>
#include <vector>
#include <iostream>

class Set {
public:
    Set(std::initializer_list<int> L = {});

    void operator+=(const Set &); //union
    void operator^=(const Set &); //intersection
    void print();

    size_t size() const;

    bool contains(const int &) const;

    bool contains(const Set &) const;

    bool subset(const Set &) const;

private:
    std::vector<int> storage;

};

Set::Set(std::initializer_list<int> L) : storage{L} {};

void Set::print() {
    for (auto it: storage)
        std::cout << it << "\t";
    std::cout << std::endl;
}

bool exists_in_vector(const std::vector<int> &v, const int &target) {
    bool res = false;
    for (auto it: v) {
        if (target == it) {
            return true;
        }
    }
    return res;
}

void Set::operator+=(const Set &X) {
    for (auto it: X.storage) {
        if (!exists_in_vector(storage, it)) {
            storage.push_back(it);
        }
    }
}

void Set::operator^=(const Set &X) {
    // do a nested for statement to find common set members
    std::vector<int> new_set;
    for (int a: storage) {
        for (int b: X.storage) {
            if (a == b) new_set.push_back(a);
        }
    }
    storage = new_set;
}

size_t Set::size() const {
    return storage.size();
}

bool Set::contains(const int &x) const {
    return exists_in_vector(storage, x);
}

bool Set::contains(const Set &setX) const {
    for (int it: setX.storage) {
        if (!this->contains(it)) {
            return false;
        }
    }
    return true;
}

bool Set::subset(const Set &parentSet) const {
    for (int it: storage) {
        if (!parentSet.contains(it)) {
            return false;
        }
    }
    return true;
}