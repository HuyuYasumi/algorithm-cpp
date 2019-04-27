#include <iostream>
using namespace std;

void chicken() {
    int x = 0, y = 0, z = 0;
    for (; x <= 20; x++) {
        for (; y <= 33; y++) {
            z = 100 - x - y;
            if ((z % 3 == 0) && (x * 5 + y * 3 + z / 3 == 100)) {
                cout << "Cock:" << x << "  Hen:" << y << "  Chick:" << z;
            }
        }
    }
}

int main() {
    chicken();
}