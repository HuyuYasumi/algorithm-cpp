#include <iostream>
#include <string>
using namespace std;

int eulidean(int x, int y);    // 使用欧几里得算法计算并返回x, y的最大公约数

int main() {
    string x, y;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << eulidean(stoi(x), stoi(y));
    return 0;
}

int eulidean(int x, int y) {
    while(x != y) {
        if (x < y) {
            int i = x;
            x = y;
            y = i;
        }
        x -= y;
    }
    return y;
}