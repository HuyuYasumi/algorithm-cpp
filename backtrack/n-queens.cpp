#include <iostream>
using namespace std;

bool OK(int k, int *X) {
    for (int i = 0; i < k; ++i) {
        if(X[i] == X[k] || abs(i - k) == abs(X[i] - X[k]))
            return false;
    }
    return true;
}

void queen(int n) {
    int X[n];
    for (int i = 0; i < n; ++i) {
        X[i] = -1;
    }
    X[0] = 0;
    int k = 1;
    while (k >= 0) {
        X[k]++;
        while (X[k] < n && !OK(k, X)) {
            X[k]++;
        }
        if(X[k] < n && k == n - 1) {
            for (int i = 0; i < n; ++i) {
                cout << X[i] << "\t";
            }
            cout << endl;
            return;
        } else if (X[k] < n) {
            k++;
        } else {
            X[k] = -1;
            k--;
        }
    }
}

int main() {
    queen(4);
    queen(8);
    return 0;
}
