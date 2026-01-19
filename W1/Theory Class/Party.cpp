#include <iostream>

struct list {
    int num;
    int val;
};

void sort(list* ar, int n) {
    if (n == 1) return;
    int k = ar[0].val;
    int m = 0;
    for (int i = 1; i < n; i++) if (ar[i].val > k) {
        k = ar[i].val;
        m = i;
    }
    list temp = ar[m];
    ar[m] = ar[n - 1];
    ar[n - 1] = temp;
    sort(ar, n - 1);
}

void display(list* ar, int i, int j) {
    for (int k = i; k < j; k++) std::cout << "item number " << ar[k].num + 1 << ", ";
    std::cout << "and item number " << ar[j].num + 1 << '.';
}

void party(list* ar, int n, long money) {
    sort(ar, n);
    int i = 0, j = n - 1;
    long sum = 0;
    for (int k = 0; k < n; k++) sum += ar[k].val;
    while (sum > money && sum - ar[j].val >= money) sum -= ar[j--].val;
    int m = i, p = j;
    long k;
    while (p < n - 1) {
        k = sum - ar[m++].val + ar[++p].val;
        if (k <= money) if (k > sum) {
            sum = k;
            i = m;
            j = p;
        }
        else break;
    }
    display(ar, i, j);
}

int main() {
    int n;
    long money;
    std::cout << "How many items are there? ";
    std::cin >> n;
    std::cout << "How much can you afford to pay in VND? ";
    std::cin >> money;
    list* ar = new list[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Input the price of item number " << i + 1 << ": ";
        std::cin >> ar[i].val;
        ar[i].num = i;
    }
    party(ar, n, money);
    delete[] ar;
}