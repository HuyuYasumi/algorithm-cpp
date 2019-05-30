#include <iostream>
using namespace std;

void solution(int* g[], int n, int x[]) {
    bool visited[n];
    n--;
    for (int i = 0; i <= n; ++i) {
        x[i] = -1;
        visited[i] = false;
    }
    x[0] = 0;
    visited[0] = true;
    int k = 1;
    while (k >= 1) {
        x[k]++;
        while(x[k] <= n) {
            if(!visited[x[k]] && g[x[k]][x[k - 1]] == 1)
                break;
            else
                x[k] += 1;
        }
        if(x[k] <= n && k == n && g[x[k]][0] == 1)
            return;
        else if(x[k] <= n && k < n) {
            visited[x[k]] = true;
            k++;
        } else {
            x[k] = -1;
            k--;
            visited[x[k]] = false;
        }
    }
}

int main() {
    int n = 5;
    int* g[] = {
            new int[n] {0, 1, 0, 1, 0},
            new int[n] {1, 0, 1, 0, 1},
            new int[n] {0, 1, 0, 1, 1},
            new int[n] {1, 0, 1, 0, 1},
            new int[n] {0, 1, 1, 1, 0}
    };
    int x[n];
    solution(g, n, x);
    for (int i = 0; i < n; ++i) {
        cout << x[i] << "  ";
    }
    return 0;
}
