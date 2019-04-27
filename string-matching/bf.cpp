#include <iostream>
#include <cstring>
using namespace std;

int bf(char S[], char T[]) {
    int sn = 0, tn = 0, result = 0;
    while( S[sn] != '\0' && T[tn] != '\0') {
        if (S[sn] == T[tn]) {
            sn++;
            tn++;
        } else {
            sn = ++result;
            tn = 0;
        }
    }
    return T[tn] == '\0' ? result + 1 : 0;
}

int main() {
    char s[] = "abcdefg";
    char t[] = "ab";
    char t2[] = "efg";
    char t3[] = "cdef";
    char t4[] = "cgdef";
    cout << bf(s, t) << endl;
    cout << bf(s, t2) << endl;
    cout << bf(s, t3) << endl;
    cout << bf(s, t4) << endl;
    return 0;
}