#include <iostream> 
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }
    return true;

}

bool isSafeRook(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }
 
    return true;

}

bool solveNQueens(vector<vector<int>>& board, int col, int N) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1, N))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void printBoard(vector<vector<int>>& board, int N) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }

}
void printBoardRook(vector<vector<int>>& board, int N) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "R " : ". ");
        }
        cout << endl;
    }

}
bool solveNRook(vector<vector<int>>& board, int col, int N, int addRook) {
    if (addRook > N) return false;
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafeRook(board, i, col, addRook)) {
            printBoardRook(board, N);
            board[i][col] = 1;
            if (solveNRook(board, col + 1, addRook, addRook))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}


int main() {
    char figure;
    cout << "Podaj figur Q lub R: " << endl;
    cin >> figure;
    cout << "Podaj liczbe wiez: " << endl;
    int addRook = 0;
    cin >> addRook;
    clock_t tStart = clock();
    int N = 30;
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (figure == 'R') {
        if (solveNRook(board, 0, N, addRook)) {
            printBoardRook(board, N);

        }
        else
        {
            cout << "Brak rozwiazania" << endl;
        }
    }
    else if (figure == 'Q') {
        if (solveNQueens(board, 0, N)) {
            printBoard(board, N);
        }
    }
    else {
        cout << "Brak rozwiązania" << endl;
    }
    printf("Time taken: %.4fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
/*
* czas hetman
1- 0.0000s
2- 0.0010s
3- 0.0000s
4- 0.0010s
5- 0.0010s
6- 0.0010s
7- 0.0020s
8- 0.0020s
9- 0.0020s
10- 0.0030s
11- 0.0040s
12- 0.0030s
13- 0.0040s
23- 0.1120s
27- 2.7140s
29- 9.2720s
*/
/*
Czas wieza
4- 0.0190s
5- 0.0250s
7- 0.0390s
9- 0.0480s
11- 0.0570s
13- 0.3310s
15- 0.3610s
17- 0.4070s
19- 0.4470s
21- 0.5030s
23- 0.5270s
25- 0.5930s
27- 0.7890s
29- 0.8010s
30- 0.8970s
*/