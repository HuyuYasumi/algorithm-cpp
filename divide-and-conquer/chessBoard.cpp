#include <iostream>
#define SIZE 1 << 3
using namespace std;


int board[SIZE][SIZE];
int Nth = 1;

void chessBoard(int bi, int bj, int si, int sj, int size) {
    if(size == 1)
        return;
    int t = Nth++;
    int min = size >> 1;

    if(si < bi + min && sj < bj + min) {
        chessBoard(bi, bj, si, sj, min);
    } else {
        board[bi + min - 1][bj + min - 1] = t;
        chessBoard(bi, bj, bi + min - 1, bj + min - 1, min);
    }

    if(si >= bi + min && sj < bj + min) {
        chessBoard(bi + min, bj, si, sj, min);
    } else {
        board[bi + min][bj + min - 1] = t;
        chessBoard(bi + min, bj, bi + min, bj + min - 1, min);
    }

    if(si < bi + min && sj >= bj + min) {
        chessBoard(bi, bj + min, si, sj, min);
    } else {
        board[bi + min - 1][bj + min] = t;
        chessBoard(bi, bj + min, bi + min - 1, bj + min, min);
    }

    if(si >= bi + min && sj >= bj + min) {
        chessBoard(bi + min, bj + min, si, sj, min);
    } else {
        board[bi + min][bj + min] = t;
        chessBoard(bi + min, bj + min, bi + min, bj + min, min);
    }
}

int main() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    chessBoard(0, 0, 2, 3, SIZE);
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            cout << board[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
