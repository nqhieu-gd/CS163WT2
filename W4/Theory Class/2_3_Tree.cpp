#include <iostream>
#include <vector>

struct store {
    bool isActive = false;
    int val;
    
    store(int x): isActive(true), val(x) {}
    ~store() {
        isActive = false;
    }
};

struct Tree {
    int val;
    Tree* left;
    Tree* right;
    store* storage;

    Tree(int a): val(a), left(nullptr), right(nullptr), storage(nullptr) {}
    ~Tree() {
        if (left) delete left;
        if (right) delete right;
        if (storage) delete storage;
    }
};

void Insert(Tree*& head, int x) {
    if (!head) head = new Tree(x);
    Tree* cur = head;
    while (cur->left && x < cur->val) {
        cur = cur->left;
        while (cur->right && x > cur->val) cur = cur->right;
    }
    if (!cur->storage) cur->storage = new store(x);
    else {
        std::vector<int> list;
        list.push_back(cur->val);
        list.push_back(x);
        list.push_back(cur->storage->val);
        if (list[1] < list[0]) std::swap(list[1], list[0]);
        if (list[1] > list[2]) std::swap(list[1], list[2]);
        if (list[1] < list[0]) std::swap(list[1], list[0]);
    }
}