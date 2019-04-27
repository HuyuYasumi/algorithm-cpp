#include <iostream>
#include <cmath>
using namespace std;

int gcd(int m, int n);
int get_stoi(int &num, string &st);

int main() {
    string x, y;
    int m, n;
    cout << "连续整数检测算法！\n";
    cout << "请输入自然数 m：";
    if(get_stoi(m, x) != 0) {
        cout << "输入类型错误\n";
        return 1;
    }
    cout << "请输入自然数 n：";
    if(get_stoi(n, y) != 0) {
        cout << "输入类型错误\n";
        return 1;
    }
    m = gcd(m, n);
    if(m != 0)
        cout << "它们的最大公约数是：" << m << endl;
    else
        cout << "它们没有最大公约数！" << endl;
    return 0;
}

int gcd(int m, int n) {
    int t = min(m, n);
    while(t != 0) {
        if(m % t == 0) {
            if(n % t == 0)
                return t;
        }
        t--;
    }
    return 0;
}

int get_stoi(int &num, string &st) {
    try {
        cin >> st;
        num = stoi(st);
        if(num < 0)
            return 1;
    } catch(invalid_argument& e) {
        return 1;
    }
    return 0;
}
