#include <iostream>
using namespace std;

int seqsearch2(int r[], int n, int k) {
    // r：被查找的数组，n：数组 r 的下标最大值，k：要查找的值
    r[0] = k;
    while (r[n] != k) {
        n--;
    }
    return n ? n + 1 : 0;
}

int main(){
    const int len = 5;
    int r[len] = { 0, 2, 9, 6, 3 };
    cout << seqsearch2(r, len - 1, 6) << endl;
    cout << seqsearch2(r, len - 1, 2) << endl;
    cout << seqsearch2(r, len - 1, 3) << endl;
    cout << seqsearch2(r, len - 1, 5) << endl;
}