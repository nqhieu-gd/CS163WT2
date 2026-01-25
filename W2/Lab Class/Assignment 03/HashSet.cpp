class MyHashSet {
public:
    int* p = nullptr;

    MyHashSet() {
        p = new int[1000000];
        int i = 1000000;
        while (i) {
            p[i - 1] = -1;
            i--;
        }
    }

    ~MyHashSet() {
        if (p) delete[] p;
    }
    
    void add(int key) {
        int k = key % 1000000;
        for (int i = 0; i < 1000000; i++) {
            int n = (k + i) % 1000000;
            if (p[n] == key) return;
            if (p[n] < 0) {
                p[n] = key;
                break;
            }
        }
    }
    
    void remove(int key) {
        int k = key % 1000000;
        for (int i = 0; i < 1000000; i++) {
            int n = (k + i) % 1000000;
            if (p[n] == -1) break;
            if (p[n] == key) {
                p[n] = -2;
                break;
            }
        }
    }
    
    bool contains(int key) {
        int k = key % 1000000;
        for (int i = 0; i < 1000000; i++) {
            int n = (k + i) % 1000000;
            if (p[n] == -1) return false;
            if (p[n] == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */