#include <iostream>
#define DIMENSION 3    // 维度
using namespace std;

int getDis(int (*Points)[DIMENSION], int i, int j) {
    int dis = 0;
    for(int d1 = 0; d1 < DIMENSION; d1++) {
        dis += (Points[i][d1] - Points[j][d1]) * (Points[i][d1] - Points[j][d1]);
    }
    return dis;
}

int recentKey(int num, int (*Points)[DIMENSION]) {
    /*
     * @param {int} num 点的数量
     * @param {int[][]} Points 点集
     */
    int idx1 = 0, idx2 = 1;
    int i = 0, j = i + 1;
    int dis  = getDis(Points, i, j);
    int min = dis;
    for(; i < num - 1; i++) {
        for(j = i + 1; j < num; j++) {
            dis = getDis(Points, i, j);
            if(dis < min) {
                min = dis;
                idx1 = i;
                idx2 = j;
            }
        }
    }
    cout << "point 1: " << idx1 << "  point 2: " << idx2 << endl;
    return min;
}

int main() {
    const int NUM  = 3;
    int Points[NUM][DIMENSION] = {{1, 2, 3}, {3, 4, 5}, {4, 5, 6}};
    recentKey(NUM, Points);
    return 0;
}