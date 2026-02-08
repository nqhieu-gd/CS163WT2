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
/*
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

    void levelOrder(Node * root) {
    int h = lvl(root);

    for (int i = 1; i <= h; i++)
        printLevel(root, i);
}

    int lvlMax(int a, int b) {
        return (a > b)? a : b;
    }

    int lvl(Node*& root) {
        if (!root) return 0;
        return 1 + lvlMax(lvl(root->left), lvl(root->right));
    }

    void printLevel(Node* root, int level) {
        if (!root) return;

        if (level == 1)
            cout << root->data << " ";
        else {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
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
  
	myTree.levelOrder(root);
    return 0;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let h be the height of tree and n be the number of nodes

Space complexity:
- lvl call itself again once on each side of the root, up to the lowest level leaf nodes -> O(n) time worst case
- lvlMax returns the higher number of the two -> O(1)
- printLevel's maximum recursive depth is h -> O(h), worst case it is O(n)
- levelOrder call printLevel exactly lvl time, which is h -> O(h)

Time complexity: 
- lvl call itself again once on each side of the root, up to the lowest level leaf nodes -> O(n) time
- lvlMax returns the higher number of the two -> O(1)
- printLevel go to the node with the exact level and print out from left to right -> worst case it is O(n)
- levelOrder call printLevel exactly lvl time, which is h, each time it call printLevel once -> h time printLevel
call -> O(n*h)
*/

/*
ALGORITHM EXPLAINATION

The lvlMax function returns the higher number between the 2 given ones and the lvl function returns the level of the
current node of the tree by utilizing lvlMax to find the level of the closest subtree.

The printLevel function will print out the current node if the given variable is 1, if not, it will lower that number
and move to the next subtree to the left and right respectively and call printLevel again, so it will print out all
nodes that are in the right level and nothing else.

The levelOrder function run the printLevel funtion with the parameter variables from 1 to the tree's level, which will
essentially print out all nodes of level from highest to lowest.
*/

/*
TEST CASE

CASE 1: Input:      1
                     \
                      2
                       \
                        5
                       /  \
                      3    6
                            \
                             4  
		Output: 1 2 5 3 6 4

CSAE 2: Input:          2
                        / \
                       0   5
                          /
                         4
                        /
                       3
		Output: 2 0 5 4 3

CASE 3: Input:       2
                       \
                        5
                       /
                      1
		Output: 2 5 1
*/