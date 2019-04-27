#include <iostream>
#include <cmath>
using namespace std;

int** gameTable(int k) {
    int size = (1 << k) + 1;
    int ** T = new int*[size];
    for(int i = 0; i < ((1 << k) + 1); i++) {
        T[i] = new int[size];
    }
    for(int i = 0; i < size; i++) {
        T[i][0] = 0;
        T[0][i] = 0;
    }
    int n = 2;
    T[1][1] = 1;
    T[1][2] = 2;
    T[2][1] = 2;
    T[2][2] = 1;

    for(int t = 1; t < k; t++) {
        int tmp = n;
        n = n << 1;

        for(int i = tmp + 1; i <= n; i++) {
            for(int j = 1; j <= tmp; j++) {
                T[i][j] = T[i - tmp][j] + tmp;
            }
        }

        for(int i = 1; i <= tmp; i++) {
            for(int j = tmp + 1; j <= n; j++) {
                T[i][j] = T[i][j - tmp] + tmp;
            }
        }

        for(int i = tmp + 1; i <= n; i++) {
            for(int j = tmp + 1; j <= n; j++) {
                T[i][j] = T[i - tmp][j - tmp];
            }
        }
    }
    return T;
}

int main() {
    const int K = 3;
    int ** T = gameTable(K);
    for(int i = 0; i <= (1 << K); i++) {
        for(int j = 0; j <= (1 << K); j++){
            cout << T[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
