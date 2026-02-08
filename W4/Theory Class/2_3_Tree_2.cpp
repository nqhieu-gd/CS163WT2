struct Tree {
    int val1, val2;
    bool twoTiming = false;
    Tree* left, * right, * middle;

    Tree(int x): val1(x), left(nullptr), right(nullptr), middle(nullptr) {}
    ~Tree() {
        if (left) delete left;
        if (right) delete right;
        if (middle) delete middle;
    }
};

