#include <iostream>
using namespace std;

int digitalTower(int* d[], int* maxSum[], int* path[], int n) {
    for (int i = 0; i < n; ++i) {
        maxSum[n - 1][i] = d[n - 1][i];
        path[n - 1][i] = i;
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            int left = d[i][j] + maxSum[i + 1][j];
            int right = d[i][j] + maxSum[i + 1][j + 1];
            if(left <= right) {
                maxSum[i][j] = right;
                path[i][j] = j + 1;
            } else {
                maxSum[i][j] = left;
                path[i][j] = j;
            }
        }
    }
    return maxSum[0][0];
}

int main() {
    const int n = 5;
    int* d[n];
    /*
    d[0] = new int[1]{8};
    d[1] = new int[2]{12, 15};
    d[2] = new int[3]{3, 9, 6};
    d[3] = new int[4]{8, 10, 4, 12};
    d[4] = new int[5]{16, 4, 18, 10, 9};
     */

    for(int i = 0; i < n; ++i) {
        d[i] = new int[i + 1];
        for(int j = 0; j <= i; ++j) {
            cout << "(" << i << "," << j << ")=";
            cin >> d[i][j];
        }
    }

    int* maxSum[n];
    int* path[n];
    for (int i = 0; i < n; ++i) {
        maxSum[i] = new int[i + 1];
        path[i] = new int[i + 1];
    }

    cout << digitalTower(d, maxSum, path, n) << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; j++) {
            cout << path[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}