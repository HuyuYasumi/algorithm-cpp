#include <iostream>
using namespace std;

int ClosestPoints(const int x[], const int y[], int n) {
    int idx1 = 0, idx2 = 1;
    int i = 0, j = i + 1;
    int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    int min = d;
    for(; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if(d < min) {
                min = d;
                idx1 = i;
                idx2 = j;
            }
        }
    }
    cout << "point 1: " << idx1 << "  point 2: " << idx2 << endl;
    return min;
}

int main() {
    int x[] = {4, 2, 1, 6, 3, 7};
    int y[] = {7, 5, 3, 9, 2, 6};
    int z[] = {6, 3, 2, 5, 7, 1};
    ClosestPoints(x, y, sizeof(x) / sizeof(int));
    ClosestPoints(x, z, sizeof(x) / sizeof(int));
    ClosestPoints(z, y, sizeof(x) / sizeof(int));
    return 0;
}