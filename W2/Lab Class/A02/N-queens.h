#include <vector>
#include <iostream>

struct Board {
private:
    int n;
    int* row, * column;
    int* dia1, * dia2;

public:
    Board(int n);
    ~Board();
    bool step(int i, int j);
    void unstep(int i, int j);
};

struct coord {
    int x;
    int y;
    coord(int a, int b);
    void display();
};

void NQueens(int n);

bool Recurse(Board& field, std::vector<coord>& v, int curRow, int n);