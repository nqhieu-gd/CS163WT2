#include <iostream>

/*
//Non-recursion
bool PlaceQueen(int m, int p, int n, int* ar) {
    if (ar[m*n + p] == -1) return 0;
    ar[m*n + p] = 1;
    for (int i = 0; i < n; i++) {
        if (ar[i*n + p] == -1) return 0;
        if (ar[m*n + i] == -1) return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i != m) ar[i*n + p] = -1;
        if (i != p) ar[m*n + i] = -1;
    }
    return 1;
}

void NumOfQueens(int n) {
    int* ar = new int[n*n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (PlaceQueen(k, i, n, ar)) {
            k++;
            continue;
        }
        else k++;
    }
}*/

//Recursion
// void ReTableUp(int* ar, int n) {
//     int* br = new int[(n + 1)*(n + 1)];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             br[i*(n + 1) + j] = ar[i*n + j];
//         }
//         if (br[(i + 1)*(n + 1) - 1] == 0) br[(i + 1)*(n + 1)] = 0;
//         else br[(i + 1)*(n + 1)] = -1;
//         if (br[(n - 1)*(n + 1) + i] == 0) br[n*(n + 1) + i] = 0;
//         else br[n*(n + 1) + i] = -1;
//     }
//     br[(n + 1)*(n + 1)] = 0;
//     delete[] ar;
//     ar = br;
// }

// void PlaceQueen(int n, int* ar) {
//     if (n == 1) {
//         ar = new int[1];
//         ar[1] = 1;
//         return;
//     }
// }

// int CalcQueen(int* ar, int n) {
//     int num = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (ar[i*n + j] == 1) {
//                 num++;
//                 break;
//             }
//         }
//     }
//     return num;
// }

// void DisplayQueen(int* ar, int n) {
//     std::cout << "_";
//     for (int i = 0; i< n; i++) std::cout << "____";
//     for (int i = 0; i < n; i++) {
//         std::cout << '|';
//         for (int j = 0; j < n; j++) {
//             if (ar[i*n + j] != 1) {
//                 std::cout << "   |";
//             }
//             else std::cout << " Q |";
//         }
//         std::cout << "_";
//         for (int i = 0; i< n; i++) std::cout << "____";
//     }
//     delete[] ar;
// }