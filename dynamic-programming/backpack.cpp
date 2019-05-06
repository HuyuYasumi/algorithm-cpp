#include <iostream>
using namespace std;

/**
 * 0/1 背包问题
 * @param w 物品的重量集
 * @param v 物品的价值集
 * @param W 背包的容量
 * @return @param select 最优解选择的物品
 * @return 最优解的总重量
 */
int backpack(int w[], int v[], int W, int select[]) {
    int n = w[0];  // 问题规模之一
    int* V[n + 1];
    for (int i = 0; i <= n; ++i) {
        V[i] = new int[W + 1];
        V[i][0] = 0;
    }
    for (int i = 1; i <= W; ++i) {
        V[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if(j >= w[i]) {
                V[i][j] = max(V[i - 1][j - w[i]] + v[i], V[i - 1][j]);
            } else {
                V[i][j] = V[i - 1][j];
            }
        }
    }
    select[0] = 0;
    int j = W;
    for (int i = n; i > 0; i--) {
        if(V[i][W] > V[i - 1][W]) {
            select[i] = 1;
            W -= w[i];
        } else
            select[i] = 0;
    }
    return V[n][j];
}

int main() {
    int n;
    cout << "The numbers of items: ";
    cin >> n;
    int w[n + 1];
    w[0] = n;
    int v[n + 1];
    v[0] = n;
    for (int i = 1; i < n + 1; ++i) {
        cout << i << ": \n";
        cout << "\tw: ";
        cin >> w[i];
        cout << "\tv: ";
        cin >> v[i];
        cout << endl;
    }
    int W;
    cout << "The backpack weight: ";
    cin >> W;
    int select[n + 1];
    cout << "result: " << backpack(w, v, W, select) << endl;
    for (int i = 0; i < n + 1; ++i) {
        cout << select[i] << "\t";
    }
    return 0;
}
