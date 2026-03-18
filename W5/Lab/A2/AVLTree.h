#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int key): key(key), left(nullptr), right(nullptr), height(1) {}
    ~Node() {
        if (left) delete left;
        if (right) delete right;
    }
};

class AVLTree {
private:
    Node* root;

    int height(Node* root) {
        if (root == nullptr)
            return 0;
        return root->height;
    }

    int getBalance(Node* root) {
        if (root == nullptr)
            return 0;
        return height(root->left) - height(root->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* sub = x->right;

        x->right = y;
        y->left = sub;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* sub = y->left;

        y->left = x;
        x->right = sub;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    void insertTo(Node*& node, int key) {
        if (node == nullptr) {
            node = new Node(key);
            return;
        }

        if (key < node->key)
            insertTo(node->left, key);
        else if (key > node->key)
            insertTo(node->right, key);
        else return;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            node = rightRotate(node);

        if (balance < -1 && key > node->right->key)
            node = leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            node = leftRotate(node);
        }
    }

public:
    AVLTree(): root(nullptr) {}

    ~AVLTree() {
    if (root != nullptr) {
        delete root;
    }
}

    void insert(int k) {
        insertTo(root,k);
    }

    Node* rootCall() {
        return root;
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the number of node => height of the tree is approximately log(n)

Space complexity:
- Tree storage: n nodes -> O(n)
- leftRotate and rightRotate: O(1)
- The insert function insert at the leaf node, so the recursion call will be called log(n) time, plus the rotating
operation, which is O(1) -> O(log(n))

Time complexity:
- leftRotate and rightRotate: O(1)
- The insert function insert at the leaf node, so the recursion call will be called log(n) time, plus the rotating
operation, which is O(1) -> O(log(n))
*/

/*
ALGORITHM EXPLAINATION

- leftRotate and rightRotate: basic AVL tree rotation functions

- insertTo: trace down to the right position and input a new node there, then check if the balance factor is still
okay, if not then, using recursion, we find the first subtree with imbalance starting from the nodes below up to
the root. Since we sort of saved the path with recursion, doing this is possible, and since the tree only becomes
imbalance after we input this key, balancing the subtree below will also balace the subtree above. If the imbalance
is a left-left type, we do right rotation; if it is a right-right type, we do left rotation; if it is left-right we
do left-right rotation and if it is right-left, we do right-left rotation.
*/