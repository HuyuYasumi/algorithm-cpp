#include <iostream>
using namespace std;

void equal711() {
    int plus = 711;
    double sum = 7.11;
    double coe = 0.01;
    double x, y, q, p;
    for(x = coe; x < sum; x += coe) {
        for(y = coe; y < sum - x; y += coe) {
            for(q = coe; q < (sum - x - y); q += coe) {
                p = sum - x - y - q;
                double result = (x * y * q * p * 100);
                if((int)result == plus) {
                    cout << "x: " << x
                         << "  y: " << y
                         << "  q: " << q
                         << "  p: " << p << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    equal711();
    return 0;
}