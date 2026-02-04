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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
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

    Node * insert(Node * root, int data) {
        if (!root) return new Node(data);
        if (data > root->data) root->right = insert(root->right,data);
        else if (data < root->data) root->left = insert(root->left,data);

        return root;
    }
    
};

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

Let n be the height of tree

Space complexity: maximum recursion depth is n, only 1 extra spaces is required
-> O(n) space

Time complexity: maximum recursion depth is n -> O(n) time
*/

/*
ALGORITHM EXPLAINATION

The Insert function will find the location that we can add "data" in, such position must be lower than all of its right-sided
nodes and higher than all of its left-sided nodes. It means, if "data" is higher than the current node's data, insert it to
the tree to the right and vice versa, the recursion will stop until a null node is reached, that node will suffice the conditions
and such is the valid position for "data".
*/

/*
TEST CASE

CASE 1: Input: 10
		Output: 10

CSAE 2: Input: 2, 5, 1
		Output:       2
                       \
                        5
                       /
                      1

CASE 3: Input: 2, 5, 0, 4, 3
		Output:          2
                        / \
                       0   5
                          /
                         4
                        /
                       3

*/