#include "AVLTree.h"
#include <fstream>

void loadTree(AVLTree& tree) {
    if (tree.rootCall() != nullptr) {
        std::cerr << "Please empty the tree before inputting a new tree.";
        return;
    }
    std::ifstream fin;
    fin.open("List.txt");
    if (!fin.is_open()) {
        std::cerr << "Error loading source file.";
        return;
    }
    int node = 0;
    while (fin >> node) {
        tree.insert(node);
    }
    if (fin.is_open()) fin.close();
}

void exportNode(Node* root, std::ofstream& fout) {
    if (!root) return;
    exportNode(root->left, fout);
    fout << root->key << ' ';
    exportNode(root->right, fout);
}

void exportTree(AVLTree& tree) {
    std::ofstream fout;
    fout.open("Traversal.txt");
    if (!fout.is_open()) {
        std::cerr << "Error loading destination file.";
        return;
    }
    exportNode(tree.rootCall(), fout);
    if (fout.is_open()) fout.close();
}

int main() {
    AVLTree tree;
    loadTree(tree);
    exportTree(tree);

    return 0;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the number of nodes => the height of the tree is approximately log(n)

Space complexity: space needed for loading the tree is n -> O(n)

Time complexity:
- loadTree: load n nodes, each time call insert once -> O(n log(n))
- exportNode traverses the whole tree from a starting root, visits each node once -> O(n)
- exportTree calls exportNode at the root -> O(n)
*/

/*
ALGORITHM EXPLAINATION

Just regular input from and output to file.
*/

/*
TEST CASE

CASE 1: Input: (empty file)
		Output: 

CASE 2: Input: 19 17 15 13 11 9 7 5 3 1 (strictly decreasing tree)
		Output: 1 3 5 7 9 11 13 15 17 19 

CASE 3: Input: 2 51 2 50 4 3 (tree with duplicate)
		Output: 2 3 4 50 51 
*/