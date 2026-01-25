class MyHashSet {
private:
    struct Node {
        int val;
        Node* next;
        Node() {
            this->next = nullptr;
        }
    };
    
public:
    Node* p = NULL;

    MyHashSet() {
        p = new Node[1000000];
        for (int i = 0; i < 1000000; i++) p[i].val = -1;
    }

    ~MyHashSet() {
        for (int i = 0; i < 1000000; i++) {
            while (p[i].next) {
                Node* cur = p[i].next;
                p[i].next = p[i].next->next;
                delete cur;
            }
        }
        if (p) delete[] p;
    }
    
    void add(int key) {
        int k = key % 1000000;
        Node* cur = &p[k];
        while (cur->val >= 0 && cur->val != key) cur = cur->next;
        if (cur->val == key) return;
        cur->val = key;
        cur->next = new Node;
        cur->next->val = -1;
    }
    
    void remove(int key) {
        int k = key % 1000000;
        Node* cur = &p[k];
        if (cur->val == key) {
            cur = cur->next;
            p[k].val = p[k].next->val;
            p[k].next = p[k].next->next;
            delete cur;
            return;
        }
        while (cur->val >= 0 && cur->val != key) cur = cur->next;
        if (cur->val == key) {
            Node* sub = cur->next;
            cur->val = sub->val;
            cur->next = sub->next;
            delete sub;
        }
    }
    
    bool contains(int key) {
        int k = key % 1000000;
        Node* cur = &p[k];
        while (cur->val >= 0 && cur->val != key) cur = cur->next;
        return (cur->val >= 0);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */