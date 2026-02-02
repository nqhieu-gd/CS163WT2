#include "N-queens.h"

Board :: Board(int n): n(n) {
        row = new int[n]();
        column = new int[n]();
        dia1 = new int[2*n - 1]();
        dia2 = new int[2*n - 1]();
}

Board :: ~Board() {
        if (row) {
            delete[] row;
            delete[] column;
            delete[] dia1;
            delete[] dia2;
        }
}

bool Board :: step(int i, int j) {
    if (row[i - 1] || column[j - 1] || dia1[i + j - 2] || dia2[i - j + n - 1]) return false;
    row[i - 1] = 1;
    column[j - 1] = 1;
    dia1[i + j - 2] = 1;
    dia2[i - j + n - 1] = 1;
    return true;
}

void Board :: unstep(int i, int j) {
    if (!row[i - 1] || !column[j - 1] || !dia1[i + j - 2] || !dia2[i - j + n - 1]) return;
    row[i - 1] = 0;
    column[j - 1] = 0;
    dia1[i + j - 2] = 0;
    dia2[i - j + n - 1] = 0;
}

coord :: coord(int a, int b): x(a), y(b) {}

void coord :: display() {
    std::cout << '(' << x << ',' << y << ")    ";
}

void NQueens(int n) {
    if (n == 1) {
        coord c(1, 1);
        c.display();
        return;
    }
    if (n == 3 || n == 2) {
        std::cout << "No solution found\n";
    }
    Board field(n);
    std::vector<coord> location;

    if (Recurse(field, location, 1, n)) {
        for (int i = 0; i < n; i++) location[i].display();
    }
}

bool Recurse(Board& field, std::vector<coord>& v, int curRow, int n) {
    if (curRow > n) return true;

    for (int col = 1; col <= n; ++col) {
        if (field.step(curRow, col)) {
            coord location(curRow, col);
            v.push_back(location);

            if (Recurse(field, v, curRow + 1, n)) {
                return true;
            }

            field.unstep(curRow, col);
            v.pop_back();
        }
    }

    return false;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the size of rows and columns of the board

Space complexity: 
- 1D arrays as container -> O(n) space
- maximum recursion depth = n -> O(n) space
- vector store location of n queens -> O(n) space
=> O(n) space

Time complexity: Recurse loops n times, each time it go to the next function call, a column was filled so if the previous
column has m options, the current column only has m - 1 options, meaning a maximum of n! options, worst case, the function call
will go through all of them
-> O(n!) time
*/

/*
ALGORITHM EXPLAINATION

The special cases (n <= 3) has been dealt with in the NQueens function, so we can assume n >= 4

The main function of this code is the Recurse function, it will "test" each row and fill in each column until a valid
setup is found. If it leads to an invalid one, redo via v.pop_back() until it comes back to the original loop, then
the next loop is executed. If no valid setup is found, return false; if a valid setup is found, then return true, as the
current function call returns true, its "master" function call also returns true and so on, hence the very original function
also returns true.
/*
TEST CASE

CASE 1: Input: 3
		Output: No solution found

CSAE 2: Input: 4
        Output: (1,2)    (2,4)    (3,1)    (4,3)
        
CASE 3: Input: 5
		Output: (1,1)    (2,3)    (3,5) (4,2)    (5,4)
*/