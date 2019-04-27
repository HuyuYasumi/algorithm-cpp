#include <iostream>
using namespace std;

void move(char A, char B) {
    cout << A << "->" << B << endl;
}

void hanoi(int n, char A, char B, char C) {
    if(n == 1)
        move(A, C);
    else {
        hanoi(n - 1, A, C, B);
        move(A, C);
        hanoi(n - 1, B, A, C);
    }
}

int main() {
    hanoi(3, 'A', 'B', 'C');
    return 0;
}