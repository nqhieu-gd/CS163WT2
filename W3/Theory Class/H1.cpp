#include <iostream>

struct chessBoard {
private:
    int** ar;
    int n;
    int x, y;

    void tile(int a, int b) {
        this->x = a;
        this->y = b;
        if (ar) if (ar[a - 1]) ar[a - 1][b - 1] = 1;
    }

public:
    chessBoard(int n, int a, int b) {
        this->n = n;
        ar = new int*[n];
        for (int i = 0; i < n; i++) {
            ar[i] = new int[n];
            for (int j = 0; j < n; j++) ar[i][j] = -1;
        }
        tile(a, b);
    }
    ~chessBoard() {
        if (ar) for (int i = 0; i < n; i++) {
            if (ar[i]) delete[] ar[i];
            else break;
        }
    }

    void move(int a, int b) {
        if (a >= 0 && a < n) if (b >= 0 && b < n) tile(a, b);
    }
};

bool step(int x, int y, chessBoard& cb);

int main() {
    int n = 0, a = 0, b = 0;
    std::cout << "Enter the size of the board:    ";
    std::cin >> n;
    std::cout << "Enter the initial row of the knight: ";
    std::cin >> a;
    std::cout << "Enter the initial column of the knight: ";
    std::cin >> b;
    chessBoard cb(n, a, b);

    return EXIT_SUCCESS;
}

bool step(int x, int y, chessBoard& cb) {
    
}