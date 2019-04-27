#include <iostream>
#include <vector>
using namespace std;

int dist(char c, char const T[], int m) {
    if(T[m] == c)
        return m;
    vector<int> v;
    for(int i = 1; i < m; i++) {
        if(T[i] == c) {
            v.push_back(i);
        }
    }
    if(v.empty()) {
        return m;
    } else {
        return m - v.back();
    }
}

int BM(char S[], char T[], int n, int m) {
    int i = m;
    int j;
    while(i <= n) {
        j = m;
        while(j > 0 && S[i] == T[j]) {
            i--;
            j--;
        }
        if(j == 0) {
            return i + 1;
        } else {
            i += dist(S[i], T, m);
        }
    }
    return 0;
}

int main() {
    char S[] = "0ababcabcacbab";
    char T1[] = "0abcac";
    char T2[] = "0aba";
    char T3[] = "0acbab";
    char T4[] = "0aecbab";
    cout << BM(S, T1, 13, 5) << endl;
    cout << BM(S, T2, 13, 3) << endl;
    cout << BM(S, T3, 13, 5) << endl;
    cout << BM(S, T4, 13, 5) << endl;
    return 0;
}