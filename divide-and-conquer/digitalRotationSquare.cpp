#include <iostream>
#define SIZE 5

void rotation(int out[][SIZE], int const in[][SIZE], int size, int begin) {
    if(size == 0)
        return;
    if(size == 1) {
        out[begin][begin] = in[begin][begin];
        return;
    }
    int i = begin, j = begin;
    for(; i < size + begin - 1; i++)
        out[i + 1][j] = in[i][j];
    for(; j < size + begin - 1; j++)
        out[i][j + 1] = in[i][j];
    for(; i > begin; i--)
        out[i - 1][j] = in[i][j];
    for(; j > begin; j--)
        out[i][j - 1] = in[i][j];
    rotation(out, in, size - 2, begin + 1);
}

int main() {
    int square[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            square[i][j] = j + i * SIZE;
    int square2[SIZE][SIZE];
    rotation(square2, square, SIZE, 0);
    return 0;
}