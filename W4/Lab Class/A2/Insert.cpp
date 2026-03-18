#include "2-3Tree.h"
#include <fstream>

void loadTree(TwoThreeTree& tree) {
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
    exportNode(root->child[0], fout);
    fout << root->val[0] << ' ';
    exportNode(root->child[1], fout);
    if (root->num == 2) {
        fout << root->val[1] << ' ';
        exportNode(root->child[2], fout);
    }
}

void exportTree(TwoThreeTree& tree) {
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
    TwoThreeTree tree;
    loadTree(tree);
    if (!tree.rootCall()) std::cerr << "Error!\n";
    exportTree(tree);

    return 0;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the number of nodes => height of the tree is log(n)

Space complexity: space needed for loading the tree is n -> O(n)

Time complexity:
- loadTree: load n nodes -> O(n)
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