#include <iostream>
using namespace std;

int coin(int coins[], int lo, int hi) {
    int size = hi - lo + 1;
    if(size == 1)
        return lo + 1;
    int size1, size2;
    int sum1 = 0, sum2 = 0;
    if(size % 3 == 0)
        size1 = size2 = size / 3;
    else
        size1 = size2 = size / 3 + 1;
    for (int i = lo; i < lo + size1; ++i) {
        sum1 += coins[i];
    }
    for (int j = lo + size1; j < lo + size1 + size2; ++j) {
        sum2 += coins[j];
    }
    if(sum1 < sum2) {
        return coin(coins, lo, lo + size1 - 1);
    } else if(sum1 > sum2) {
        return coin(coins, lo + size1, lo + size1 + size2 - 1);
    } else {
        return coin(coins, lo + size1 + size2, hi);
    }
}

int main() {
    int size;
    int Nth;
    cout << "The numbers of coins: ";
    cin >> size;
    cout << "The serial number of fake coin: ";
    cin >> Nth;
    int coins[size];
    for(int i = 0; i < size; i++) {
        if(i == Nth - 1){
            coins[i] = 1;
        } else {
            coins[i] = 2;
        }
    }
    cout << "I guess the " << coin(coins, 0, size - 1) << "th is the fake coin." << endl;
    return 0;
}
