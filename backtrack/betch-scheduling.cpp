#include <iostream>
using namespace std;

int betch(int n, int a[], int b[]) {
    int best = 0x7fffffff;
    int sum1[n], sum2[n], x[n];
    bool visited[n];
    for (int i = 0; i < n; ++i) {
        sum1[i] = 0;
        sum2[i] = 0;
        x[i] = -1;
        visited[i] = false;
    }
    int k = 0;
    while (k >= 0) {
        x[k]++;
        while (x[k] < n) {
            if(!visited[x[k]]) {
                if(k == 0) {
                    sum1[0] = a[x[k]];
                    sum2[0] = sum1[0] + b[x[k]];
                } else {
                    sum1[k] = sum1[k - 1] + a[x[k]];
                    sum2[k] = max(sum2[k - 1], sum1[k]) + b[x[k]];
                }
                if (sum2[k] < best)
                    break;
            }
            x[k]++;
        }
        if (x[k] < n && k < n - 1) {
            visited[x[k]] = true;
            k++;
        } else {
            if (x[k] < n) {
                /*
                cout << "one of the scheduling method : ";
                for (int i = 0; i < n; ++i) {
                    cout << x[i] << "  ";
                }
                cout << endl;
                 */
                if (best > sum2[k])
                    best = sum2[k];
            }
            x[k] = -1;
            k--;
            visited[x[k]] = false;
        }
    }
    return best;
}

int main() {
    int n = 3;
    int a[] = {2, 3, 2};
    int b[] = {1, 1, 3};
    cout << betch(n, a, b) << endl;
    return 0;
}
