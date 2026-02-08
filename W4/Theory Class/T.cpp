#include <iostream>

struct Tree {
    int val;
    Tree* left;
    Tree* right;

    Tree(int a): val(a), left(nullptr), right(nullptr) {}
    ~Tree() {
        if (left) delete left;
        if (right) delete right;
    }
};

void Input(Tree*& head, int a) {
    if (head == nullptr) {
        head = new Tree(a);
        return;
    }
    if (head->val < a) {
        if (head->right == nullptr) head->right = new Tree(a);
        else Input(head->right, a);
    }
    else  {
        if (head->left == nullptr) head->left = new Tree(a);
        else Input(head->left, a);
    }
}

void Display(Tree* head) {
    if (head == nullptr) return;
    Display(head->left);
    std::cout << "  " << head->val << "  ";
    Display(head->right);
}

void Range(Tree* head, int x, int y) {
    if (!head) return;
    std::cout << '(';
    Range(head->left, x, y);
    if (x <= head->val && y >= head-> val) {
        std::cout << head->val << "  ";
    }
    Range(head->right, x, y);
    
    std::cout << ')';
}

Tree* Closest(Tree* head, int x) {
    if (!head) return nullptr;
    Tree* cur = head;
    if (x < head->val) {
        if (x < head->left->val || head->val - x > x - head->left->val) cur = Closest(head->left, x);
    }
    else if (x > head->val) {
        if (x > head->right->val || head->val - x < x - head->right->val) cur = Closest(head->right, x);
    }
    return cur;
}

Tree* Ancestor(Tree* head, int x, int y) {
    if (!head) return nullptr;
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    while (head->val > y || head->val < x) {
        while (head->val > y) head = head->left;
        while (head->val < x) head = head->right;
    }
    return head;
}

void Remove1c(Tree* head, int x) {
    if (!head) return;
    while (head) {
        if (x < head->val) head = head->left;
        if (x > head->val) head = head->right;
    }
    if (head->left) {
        Tree* sub = head->left;
        while (sub->right) sub = sub->right;
        head->val = sub->val;
        delete sub;
    }
    else if (head->right) {
        head->val = head->right->val;
        Tree* sub = head->right;
        head->right = head->right->right;
        head->left = head->right->left;
        delete sub;
    }
    else delete head;
}

void Remove2c(Tree*& head, int x) {
    if (!head) return;
    Tree* cur = head;
    while (cur) {
        if (x < cur->val) cur = cur->left;
        if (x > cur->val) cur = cur->right;
    }
    if (cur) {
        Remove1c(cur, cur->left->val);
        Remove1c(cur, cur->right->val);
    }
}

int lvlMax(int a, int b) {
    return (a > b)? a : b;
}

int lvlLeft(Tree* root) {
    if (!root) return 0;
    return 1 + lvlMax(lvlLeft(root->left), lvlRight(root->left));
}

int lvlRight(Tree* root) {
    if (!root) return 0;
    return 1 + lvlMax(lvlLeft(root->right), lvlRight(root->right));
}

void rotate(Tree*& root, int side) {
    if (side == 0 && root->right) {
        Tree* cur = root;
        root = root->right;
        if (root->left) cur->right = root->left;
        root->left = cur;
    }
    else if (side == 1 && root->left) {
        Tree* cur = root;
        root = root->left;
        if (root->right) cur->left = root->right;
        root->right = cur;
    }
}

void Balance(Tree*& root) {
    if (!root) return;
    Tree* cur = root;
    int sub = lvlLeft(root) - lvlRight(root);
    if (sub < 2 && sub > -2) {
        Balance(root->right);
        Balance(root->left);
        return;
    }
    else {
        if (sub > 0) {
            if (lvlLeft(root->left) > lvlRight(root->left))
        }
    }
}

int main() {
    Tree* head = nullptr;
    Input(head, 739);
    Input(head, 543);
    Input(head, 43);
    Input(head, 25435);
    Input(head, 2);
    Input(head, 435);
    Input(head, 32);
    Input(head, 5);
    Input(head, 243);
    Display(head);
    // Range(head, 18, 360);
    // std::cout << '\n';
    // Tree* cs = Closest(head, 360);
    // if (cs) std::cout << cs->val;
    // Tree* act = Ancestor(head, 25435, 5);
    // if (act) std::cout << '\n' << act->val;

    if(head) delete head;

    return 0;
}