#include <iostream>

struct Tree {
    int cap;
    int val1, val2;
    bool isLeaf;
    Tree* left;
    Tree* right;
    Tree* mid;

    Tree(): cap(0), left(nullptr), right(nullptr), mid(nullptr), isLeaf(true) {}
    Tree(bool leaf): cap(0), left(nullptr), right(nullptr), mid(nullptr), isLeaf(leaf) {}
    ~Tree() {
        if (left) delete left;
        if (right) delete right;
        if (mid) delete mid;
    }
};

Tree* construct(Tree* root) {
    root = new Tree;
    root->left = new Tree;
    root->right = new Tree;
    root->isLeaf = false;
    return root;
}

class TwoThreeTree
{
private:
    Tree* root;

    void splitChild(Tree* parent, int i, Tree* node)
    {
        Tree* newNode = new Tree(node->isLeaf);

        newNode->cap = 1;
        newNode->val1 = node->val2;

        if(!node->isLeaf)
        {
            newNode->left = node->right;
        }

        node->cap = 1;

        for(int j = parent->cap; j > i; j--)
            parent->child[j+1] = parent->child[j];

        parent->child[i+1] = newNode;

        for(int j = parent->cap-1; j >= i; j--)
            parent->key[j+1] = parent->key[j];

        parent->key[i] = node->val2;
        parent->cap++;
    }

    void insertNonFull(Tree* node, int k)
    {
        int i = node->cap - 1;

        if(node->isLeaf)
        {
            while(i >= 0 && k < node->key[i])
            {
                node->key[i+1] = node->key[i];
                i--;
            }

            node->key[i+1] = k;
            node->cap++;
        }
        else
        {
            while(i >= 0 && k < node->key[i])
                i--;

            i++;

            if(node->child[i]->cap == 2)
            {
                splitChild(node, i, node->child[i]);

                if(k > node->key[i])
                    i++;
            }

            insertNonFull(node->child[i], k);
        }
    }

    void print(Tree* node, int level)
    {
        if(node == NULL) return;

        cout << "Level " << level << " : ";

        for(int i=0;i<node->cap;i++)
            cout << node->key[i] << " ";

        cout << endl;

        for(int i=0;i<=node->cap;i++)
            print(node->child[i], level+1);
    }

public:

    TwoThreeTree()
    {
        root = NULL;
    }

    void insert(int k)
    {
        if(root == NULL)
        {
            root = new Tree(true);
            root->val1 = k;
            root->cap = 1;
        }
        else
        {
            if(root->cap == 2)
            {
                Tree* newRoot = new Tree(false);
                newRoot->left = root;

                splitChild(newRoot,0,root);

                int i = 0;
                if(newRoot->val1 < k)
                    i++;

                insertNonFull(newRoot->child[i],k);

                root = newRoot;
            }
            else
            {
                insertNonFull(root,k);
            }
        }
    }

    void display()
    {
        print(root,0);
    }
};