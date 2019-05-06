#include <iostream>
using namespace std;

/**
 * 最长子序列
 * @param nums 待求解的问题
 * @return @param sub 子问题的最长子序列，第一列存储了最长子序列的长度
 * @param n 问题规模
 */
void solutionA(int nums[], int* sub[], int n) {
    sub[0] = new int[n + 1];
    sub[0][0] = 1;
    sub[0][1] = nums[0];
    for (int i = 1; i < n; ++i) {
        sub[i] = new int[n + 1];
        sub[i][0] = 1;
        sub[i][1] = nums[i];
        for (int j = i - 1; j >= 0; --j) {
            if(nums[i] >= nums[j]) {
                if(sub[i][0] < sub[j][0] + 1) {
                    sub[i][0] = sub[j][0] + 1;
                    for(int k = 1; k < sub[i][0]; k++) {
                        sub[i][k] = sub[j][k];
                    }
                    sub[i][sub[i][0]] = nums[i];
                }
            }
        }
    }
}

int main() {
    int n = 8;
    cout << "The length of nums: ";
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        cin >> nums[i];
    }
    int* sub[n];
    solutionA(nums, sub, n);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sub[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
