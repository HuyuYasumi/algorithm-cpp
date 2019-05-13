#include <iostream>
using namespace std;

bool Ok(int n, int *g[], int x[], int k) {
    for (int i = 0; i <= n; ++i) {
        if(g[k][i] == 1 && x[i] == x[k])
            return false;
    }
    return true;
}

void solution(int n, int *g[], int m) {
    int x[n];
    n--;
    for (int i = 0; i <= n; ++i) {
        x[i] = 0;
    }
    int k = 0;
    while (k >= 0) {
        x[k]++;
        while(x[k] <= m) {
            if (Ok(n, g, x, k)) break;
            else
                x[k]++;
        }
        if(x[k] <= m && k == n) {
            for (int i = 0; i <= n; ++i) {
                cout << x[i] << "\t";
            }
            return;
        } else if (x[k] <= m && k < n) {
            k++;
        } else {
            x[k] = 0;
            k--;
        }
    }
}

int main() {
    int n = 5;
    int m = 3;
    /*
    int g[5][5] = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 1},
            {1, 1, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 1, 1, 1, 0},
    };
    int* g2[n];
    for(int i = 0; i < n; ++i) {
        g2[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            g2[i][j] = g[i][j];
        }
    }
     */
    int vnum, arcnum;  // 顶点数, 边数
    cout << "vum, arcnum: ";
    cin >> vnum >> arcnum;
    int *g2[vnum];
    for (int i = 0; i < vnum; i++) {
        g2[i] = new int[vnum];
        for (int j = 0; j < vnum; ++j) {
            g2[i][j] = 0;
        }
    }
    for (int i = 0; i < arcnum; i++) {
        cout << "Please enter two verices number: ";
        int v1, v2;  // 边的两个顶点
        cin >> v1 >> v2;
        g2[v1][v2] = 1;
        g2[v2][v1] = 1;
    }
    cout << "m ";
    cin >> m;
    solution(n, g2, m);
    return 0;
}