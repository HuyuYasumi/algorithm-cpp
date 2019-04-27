#include <iostream>
using  namespace std;

int multiSegmentGrahp(int* g[], int cost[], int path[], int n) {
    cost[n - 1] = 0;
    for(int i = n - 1; i >= 0; --i) {
        for(int j = i - 1; j >= 0; --j) {
            int tmp = g[i][j] + cost[i];
            if(tmp < cost[j]) {
                cost[j] = tmp;
                path[j] = i;
            }
        }
    }
    return cost[0];
}

int main() {
    const int MAX = 1000;
    int vnum, arcnum;
    cout << "vum, arcnum: ";
    cin >> vnum >> arcnum;
    int* g[vnum];
    for(int i = 0; i < vnum; i++) {
        g[i] = new int[vnum];
        for(int j = 0; j < vnum; ++j) {
            g[i][j] = MAX;
        }
    }
    for(int i = 0; i < arcnum; i++) {
        cout << "Please enter two verices number and weight: ";
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g[v1][v2] = w;
    }

    int cost[vnum];
    int path[vnum];
    for(int i = 0; i < vnum; i++) {
        cost[i] = MAX;
        path[i] = -1;
    }
    cout << "minSum: " << multiSegmentGrahp(g, cost, path, vnum) << endl;
    cout << "path:\t";
    for(int i = 0; i != -1;) {
        cout << path[i] << "\t";
        i = path[i];
    }
    return 0;
}
