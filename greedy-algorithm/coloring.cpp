#include <iostream>
using namespace std;

bool conflict(int *g[], int n, int color[], int i, int k) {
    for (int j = 0; j < n; ++j) {
        if (g[i][j] == 1 && k == color[j])
            return true;
    }
    return false;
}

int coloring(int *g[], int n, int color[]) {
    color[0] = 1;
    for (int i = 1; i < n; ++i) {
        color[i] = 0;
    }
    int k = 0, flag = n;
    while(flag > 1) {
        k++;
        for (int i = 1; i < n; ++i) {
            if(color[i] == 0 && !conflict(g, n, color, i, k)) {
                color[i] = k;
                flag--;
            }
        }
    }
    return k;
}

int main() {
    int n = 5;
    int g[5][5] = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0},
    };
    int *g2[n];
    for (int i = 0; i < n; ++i) {
        g2[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            g2[i][j] = g[i][j];
        }
    }
    int color[n];
    cout << coloring(g2, n, color) << endl;
    for (int i = 0; i < n; ++i) {
        cout << color[i] << "\t";
    }
    return 0;
}