#include <iostream>
using namespace std;

int median(int n1[], int lo1, int hi1, int n2[], int lo2, int hi2) {
    if(lo1 == hi1 && lo2 == hi2)
        return n1[lo1] <= n2[lo2] ? n1[lo1] : n2[lo2];
    if(lo1 == hi1)
        return n1[lo1];
    if(lo2 == hi2)
        return n2[lo2];
    int m1 = (lo1 + hi1) >> 1;
    int m2 = (lo2 + hi2) >> 1;
    if(n1[m1] == n2[m2])
        return n1[m1];
    if(n1[m1] < n2[m2])
        return median(n1, m1, hi1, n2, lo2, m2);
    return median(n1, lo1, m1, n2, m2, hi2);
}

int main() {
    int n1[] = {11, 13, 15, 17, 19};
    int n2[] = {2, 4, 10, 14, 20, 24, 34};
    cout << median(n1, 0, 4, n2, 0, 6);
    return 0;
}
