#include <iostream>

using namespace std;

int TSP(int *g[], int n) {
    int vn = 1 << (n - 1);
    int DEFAULTDIS = 60000;
    int d[n][vn];
    int temp, minDis = DEFAULTDIS;
    for (int i = 1; i < n; i++) {
        d[i][0] = g[i][0];
    }

    for (int j = 1; j < vn; j++) {
        for (int i = 1; i < n; i++) {
            if ((vn & j) == 0) {
                minDis = DEFAULTDIS;
                for (int k = 1; k < n; k++) {
                    if (((1 << (k - 1)) & j) != 0) {
                        temp = g[i][k] + d[k][j - (1 << (k - 1))];
                        if (temp < minDis) {
                            minDis = temp;
                        }
                    }
                }
            }
            d[i][j] = minDis;
        }
    }
    minDis = DEFAULTDIS;
    for (int k = 1; k < n; k++) {
        temp = g[0][k] + d[k][(vn - 1) - (1 << (k - 1))];
        if (minDis > temp) {
            minDis = temp;
        }
    }
    return d[0][vn - 1] = minDis;
}

int main() {
    const int MAX = 1000;
    int vnum, arcnum;
    cout << "vum, arcnum: ";
    cin >> vnum >> arcnum;
    int *g[vnum];
    for (int i = 0; i < vnum; i++) {
        g[i] = new int[vnum];
        for (int j = 0; j < vnum; ++j) {
            g[i][j] = MAX;
        }
    }
    for (int i = 0; i < arcnum; i++) {
        cout << "Please enter two verices number and weight: ";
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g[v1][v2] = w;
    }

    cout << TSP(g, vnum);
    return 0;
}
