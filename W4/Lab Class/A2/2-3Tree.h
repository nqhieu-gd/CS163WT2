#pragma once

#include <iostream>

struct Node {
    int val[2];
    Node* child[4];
    Node* parent;
    int num;
    bool leaf;

    Node(bool isLeaf) {
        num = 0;
        leaf = isLeaf;
        for(int i = 0;i < 4;i++) child[i] = nullptr;
        parent = nullptr;
    }
    ~Node() {
        for(int i = 0;i < 4;i++) if (child[i]) delete child[i];
        parent = nullptr;
    }
};

class TwoThreeTree {
private:
    Node* root;

    void splitNode(int k, Node* node) {
        Node* newNode = new Node(node->leaf);
        if (k > node->val[1]) std::swap(k, node->val[1]);
        else if (k < node->val[0]) std::swap(k, node->val[0]);
        newNode->val[0] = node->val[1];
        newNode->parent = node->parent;
        if (node->num == 3) {
            newNode->child[0] = node->child[2];
            newNode->child[0]->parent = newNode;
            newNode->child[1] = node->child[3];
            newNode->child[1]->parent = newNode;
            node->child[2] = nullptr;
            node->child[3] = nullptr;
        }
        node->num = 1;
        newNode->num = 1;
        if (node->parent == nullptr) {
            Node* newRoot = new Node(false);
            newRoot->num = 1;
            newRoot->val[0] = k;
            newRoot->child[0] = node;
            node->parent = newRoot;
            newRoot->child[1] = newNode;
            newNode->parent = newRoot;
            root = newRoot;
        }
        else if (node->parent->num == 1) {
            node->parent->num = 2;
            node->parent->val[1] = k;
            if (k < node->parent->val[0]) std::swap(node->parent->val[0], node->parent->val[1]);
            if (node == node->parent->child[0]) {
                node->parent->child[2] = node->parent->child[1];
                node->parent->child[1] = newNode;
            }
            else node->parent->child[2] = newNode;
        }
        else {
            int i = 2;
            while (i >= 0 && node != node->parent->child[i]) i--;
            int tail = 3;
            while (tail > i) {
                node->parent->child[tail] = node->parent->child[tail - 1];
                tail--;
            }
            node->parent->child[i + 1] = newNode;
            node->parent->num = 3;
            splitNode(k, node->parent);
        }
    }

    void insertTo(Node* node, int k) {
        if(node->leaf) {
            if (k == node->val[0]) return;
            if (node->num == 2) {
                if (k == node->val[1]) return;
                else splitNode(k, node);
            }
            else {
                node->num = 2;
                if (k < node->val[0]) std::swap(k, node->val[0]);
                node->val[1] = k;
            }
        }
        else {
            int i = 0;
            while(i < node->num && k > node->val[i]) i++;
            if (k == node->val[i]) return;
            insertTo(node->child[i], k);
        }
    }

public:
    TwoThreeTree() {
        root = nullptr;
    }
    ~TwoThreeTree() {
        if (root) delete root;
        root = nullptr;
    }

    void insert(int k) {
        if (root == nullptr) {
            root = new Node(true);
            root->val[0] = k;
            root->num = 1;
        }
        else {
            insertTo(root,k);
        }
    }

    Node* rootCall() {
        return root;
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the number of node => height of the tree is log(n)

Space complexity:
- Tree storage: O(n)
- The insert function insert at the leaf node, so the recursion call will be called log(n) time -> O(log(n))
- splitNode: 
    + Best case: the node split once -> O(1)
    + Worst case: the node split and its parent also split, up to the root -> O(log(n))

Time complexity:
- The insert function insert at the leaf node, so the recursion call will be called log(n) time -> O(log(n))
- splitNode: 
    + Best case: the node split once -> O(1)
    + Worst case: the node split and its parent also split, up to the root -> O(log(n))
*/

/*
ALGORITHM EXPLAINATION

- Node structure:
    + val[2]: array of 2 elements, indicates that a node can store up to 2 values.
    + child[4]: regularly, a node in 2-3 tree has up to 3 children, the 4th slot in this array is only there to act as a temporary
    space for the splitting function.
    + num ranges from 1 to 2 in every case, except during splitting, num can be 3 to indicate the special situation.
    + parent is a pointer points to the parent node of the current node, with root node having no parent.
    + leaf shows if the current node is a leaf or not.

- splitNode: When inserting a value to a node that already stores 2 values, a splitting happens. First, a new node is created as
a seperated node, then we examine the inserted number and the 2 stored values to find the value to be promoted, between the other
two, the higher one will become the new node we just created, the lower one stay in the old node and that node becomes a node that
stores only 1 value. Then the promoted number will go up to the parent node, then see if it is available to add more value, if not
continue splitting. (Special case: when the parent node is also full, that means it already has 3 children, the new node we just
created will use the extra space, then sort 3 node based one their stored value. Their parent node, when splitting, will get them
as child nodes accordingly.)

- insertTo: Since in 2-3 tree, we input from the lowest floor first, if the current node is a leaf node we will just input after
checking for splitting. If not, we will find the exact spot child node number i such that stored value number i - 1 is lower than
 and stored value number i is higher than the inserted value.
*/