#include <iostream>
using namespace std;

long russian(long a, long b) {
    if(a == 1)
        return b;
    if((a & 1) == 0)
        return  russian(a >> 1, b << 1);
    else
        return b + russian((a - 1) >> 1, b << 1);
}

int main() {
    int a = 0, b = 0;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << russian(a, b);
    return 0;
}
