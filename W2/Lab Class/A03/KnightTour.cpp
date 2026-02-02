#include "KnightTour.h"

bool isSafe(int x, int y, int n, const std::vector<std::vector<int>>& board) {
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

bool Recurse(int x, int y, int moveIdx, int n, std::vector<std::vector<int>>& board, int xMove[], int yMove[]) {
    if (moveIdx == n*n) return true;

    for (int k = 0; k < 8; k++) {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];

        if (isSafe(next_x, next_y, n, board)) {
            board[next_x][next_y] = moveIdx + 1;
            
            if (Recurse(next_x, next_y, moveIdx + 1, n, board, xMove, yMove))
                return true;

            board[next_x][next_y] = -1;
        }
    }
    return false;
}

void KnightTour(int n) {
    std::vector<std::vector<int>> board(n, std::vector<int>(n, -1));

    board[0][0] = 1;

    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    if (Recurse(0, 0, 1, n, board, xMove, yMove)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                std::cout << std::setw(3) << board[i][j] << " ";
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution found\n";
    }
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the size of rows and columns of the board

Space complexity: 
- 2D arrays as container -> O(n^2) space
- maximum recursion depth is n^2, no extra spaces required -> O(n^2) space
=> O(n^2) space

Time complexity: each time a knight moves, it can choose 1 of its maximum of 8 directions to move, maximum number of
step shoule be n^2 (the board size)
-> O(8^(n^2)) time
*/

/*
ALGORITHM EXPLAINATION

int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
=> combination of every moves possible, with i means go i step alongside x/y axis
=> move i will result in xMove[i] and yMove[i], meaning go j step alongside x and k steps alongside y, with j and k's value are 1 and 2
or 2 and 1

The main function of this code is the Recurse function, it will "test" each movement continously, if a movement will eventually
lead to stuck, it will try another one, ultimately, it will just bruteforce every moves possible to see if there is a valid path
for the knight
/*
TEST CASE

CASE 1: Input: 1
		Output: 1

CSAE 2: Input: 2
        Output: No solution found
        
CASE 3: Input: 5
		Output:     1  20   9  14   3
                    10  15   2  19   8
                    21  24  17   4  13
                    16  11  22   7  18
                    25   6  23  12   5

*/