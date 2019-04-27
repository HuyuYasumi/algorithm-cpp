#include <iostream>
#include <ctime>

#define NUMS 6
using namespace std;

int G[NUMS][NUMS];
int visited[NUMS][NUMS];

void euler(int u) {
    for (int v = 0; v < NUMS; v++) {
        if (G[u][v] && !visited[u][v]) {
            visited[u][v] = visited[v][u] = 1;
            euler(v);
            cout << u << "->" << v << endl;
        }
    }
}

int main() {
//    G[1][2] = G[2][1] = G[1][3] = G[3][1] = G[1][4] = G[4][1] = 1;
//    G[2][3] = G[3][2] = G[2][4] = G[4][2] = 1;
//    G[3][4] = G[4][3] = G[3][5] = G[5][3] = 1;
//    G[4][5] = G[5][4] = 1;
    G[1][2] = G[2][1] = G[1][3] = G[3][1] = 1;
    G[2][3] = G[3][2] = 1;
    G[3][4] = G[4][3] = G[3][5] = G[5][3] = 1;
    G[4][5] = G[5][4] = 1;
    euler(1);
    return 0;
}
