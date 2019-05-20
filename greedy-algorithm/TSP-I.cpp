#include <iostream>
using namespace std;

int tsp_I(int *w[], int P[], int n) {
    int visited[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    P[0] = 0;
    visited[0] = true;
    int res = 0, min, idx;
    for (int s = 0; s < n - 1;) {
        min = 0;
        idx = -1;
        int i = 1;
        for (; min == 0 && i < n; ++i) {
            if (!visited[i] && w[P[s]][i] > 0) {
                idx = i;
                min = w[P[s]][i];
            }
        }
        for (; i < n; ++i) {
            if (!visited[i] && min > w[P[s]][i]) {
                min = w[P[s]][i];
                idx = i;
            }
        }
        res += min;
        P[++s] = idx;
        visited[idx] = true;
    }
    return res + w[idx][0];
}

int main() {
    int n = 5;
    int g[5][5] = {
            {0, 3, 3, 2, 6},
            {3, 0, 7, 3, 2},
            {3, 7, 0, 2, 5},
            {2, 3, 2, 0, 3},
            {6, 2, 5, 3, 0},
    };
    int *g2[n];
    for (int i = 0; i < n; ++i) {
        g2[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            g2[i][j] = g[i][j];
        }
    }
    int P[n];
    cout << tsp_I(g2, P, n) << endl;
    for (int k = 0; k < n; ++k) {
        cout << P[k] << "\t";
    }
    cout << endl;
    return 0;
}