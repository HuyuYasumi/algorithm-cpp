#include <iostream>
using namespace std;

int solutionA(char A[], char B[], char X[], int n, int m) {
    int* L[n + 1];
    int* S[n + 1];

    for (int i = 0; i <= n; ++i) {
        L[i] = new int[m + 1];
        L[i][0] = 0;
        S[i] = new int[m + 1];
        S[i][0] = 0;
    }
    for (int i = 0; i <= m; ++i) {
        L[0][i] = 0;
        S[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(A[i - 1] == B[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 1;
            } else if(L[i][j - 1] >= L[i - 1][j]) {
                L[i][j] = L[i][j - 1];
                S[i][j] = 2;
            } else {
                L[i][j] = L[i - 1][j];
                S[i][j] = 3;
            }
        }
    }

    for (int i = n, j = m, idx = L[n][m] - 1; i > 0 && j > 0;) {
        if(S[i][j] == 1) {
            X[idx--] = A[i-- - 1];
            j--;
        } else if(S[i][j] == 2) {
            j--;
        } else if(S[i][j] == 3) {
            i--;
        }
    }
    return L[n][m];
}

int main() {
    int n = 6;
    int m = 9;
    cout << "The length of Sequence A: ";
    cin >> n;
    char A[n];
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        cin >> A[i];
    }
    cout << "The length of Sequence B: ";
    cin >> m;
    char B[m];
    for (int i = 0; i < m; ++i) {
        cout << i << ": ";
        cin >> B[i];
    }
//    char A[] = {'a', 'b', 'c', 'b', 'd', 'b'};
//    char B[] = {'a', 'c', 'b', 'b', 'a', 'b', 'd', 'b', 'b'};
    char X[n];
    int r = solutionA(A, B, X, n, m);
    cout << "Result: " << r << endl;
    cout << "X:\t";
    for (int i = 0; i < r; ++i) {
        cout << X[i] << "\t";
    }
    return 0;
}
