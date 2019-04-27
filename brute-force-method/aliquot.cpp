#include <iostream>
using namespace std;

bool aliquot(int num) {
    int sum = 0;
    const int DIVIDEND = 11;
    while (num > 100) {
        sum += num % 100;
        num /= 100;
    }
    sum += num;
    return sum % DIVIDEND == 0;
}

int main() {
    int num;
    cout << "num: ";
    cin >> num;
    std::cout << aliquot(num) << std::endl;
    return 0;
}