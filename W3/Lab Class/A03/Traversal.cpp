#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void preOrder(Node *root) {
        if (root == nullptr) return;
        std::cout << root->data << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.preOrder(root);
    return 0;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let h be the height of tree and n be the number of nodes

Space complexity: maximum recursion depth is h, no extra spaces is required
-> worst case: O(n) space (the tree is a singly linked list), average case: O(log(n))

Time complexity: the preOrder function visits each node exactly once
-> O(n) time
*/

/*
ALGORITHM EXPLAINATION

The preOrder function will print out the current node, then try to call preOrder again to print out the left-sided
node and the rights-sided node of the current one, it recursively call preOrder so as to print out the whole tree. It
does nothing for a null node.
*/

/*
TEST CASE

CASE 1: Input:  7
                50 30 70 20 40 60 80
		Output: 50 30 20 40 70 60 80

CSAE 2: Input:  5
                1 2 3 4 5
		Output: 1 2 3 4 5

CASE 3: Input: 1 2 5 0 4 3
		Output: 1 0 2 5 4 3
*/