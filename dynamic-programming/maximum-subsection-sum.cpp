#include <iostream>
using namespace std;

int maxSub(const int nums[],int n) {
    int T[n][n];
    int maxRes = nums[0];
    for (int i = 0; i < n; ++i) {
        T[i][i] = nums[i];
        maxRes = max(maxRes, T[i][i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            T[i][j] = T[i][j - 1] + nums[j];
            maxRes = max(maxRes, T[i][j]);
        }
    }
    return maxRes;
}

int main() {
    int n = 0;
    cout << "n: ";
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        cin >> nums[i];
    }
    cout << "result: " << maxSub(nums, n);
    return 0;
}
