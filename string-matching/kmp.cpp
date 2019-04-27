#include <iostream>
#include <vector>
using namespace std;

void MakeNext(const char P[], int next[]) {
    int m = static_cast<int>(_mbstrlen(P));
    next[0] = 0;
    for (int q = 1, k = 0; q < m; ++q)
    {
        while (k > 0 && P[q] != P[k])
            k = next[k - 1];
        if (P[q] == P[k])
            k++;
        next[q] = k;
    }
}

int KMP(char const S[], char const T[]) {
    int i = 0, j = 0;
    int len = static_cast<int>(_mbstrlen(T));
    int next[len];
    MakeNext(T, next);
    while(S[i] != '\0' && T[j] != '\0') {
        if(S[i] == T[j]) {
            i++;
            j++;
        } else {
            if(j - 1 < 0) {
                i++;
                j++;
            } else {
                j = next[j -1];
            }
        }
    }
    if(T[j] == '\0')
        return (i - len + 1);
    else return 0;
}

int main() {
    char S[] = "bbc abcdab abcdabcdabde";
    char T1[] = "abcdabd";
    char T2[] = "bbc a";
    char T3[] = " abcdab a";
    char T4[] = "abde";
    char T5[] = "bfde";
    cout << KMP(S, T1) << endl;
    cout << KMP(S, T2) << endl;
    cout << KMP(S, T3) << endl;
    cout << KMP(S, T4) << endl;
    cout << KMP(S, T5) << endl;
    return 0;
}