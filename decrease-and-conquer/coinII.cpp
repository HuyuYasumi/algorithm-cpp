#include <iostream>
using namespace std;

void coin(int coins[], int lo, int hi) {
    int size = hi - lo + 1;
    int size1 = 3, size2 = 3;
    int sum1 = 0, sum2 = 0;
    for (int i = lo; i < lo + size1; ++i) {
        sum1 += coins[i];
    }
    for (int j = lo + size1; j < lo + size1 + size2; ++j) {
        sum2 += coins[j];
    }
    int i, j;
    if(sum1 == sum2) {
        if(coins[6] < coins[0])
            cout << "I guess the " << 8 << "th is the fake coin. Smaller" << endl;
        else if(coins[6] > coins[0])
            cout << "I guess the " << 7 << "th is the fake coin. Bigger" << endl;
        else {
            if(coins[7] < coins[0])
                cout << "I guess the " << 7 << "th is the fake coin. Smaller" << endl;
            else
                cout << "I guess the " << 8 << "th is the fake coin. Bigger" << endl;
        }
    } else {
        int sum11 = coins[0] + coins[4];
        int sum22 = coins[3] + coins[1];
        if(sum11 == sum22)
            i = 2, j = 5;
        else {
            if (sum1 < sum2) {
                if (sum11 < sum22) {
                    i = 0, j = 3;
                } else
                    i = 1, j = 4;
            } else {
                if (sum11 < sum22) {
                    i = 4, j = 1;
                } else
                    i = 3, j = 0;
            }
        }
        if (coins[i] < coins[6])
            cout << "I guess the " << i + 1 << "th is the fake coin. Smaller" << endl;
        if (coins[j] > coins[6])
            cout << "I guess the " << j + 1 << "th is the fake coin. Bigger" << endl;
    }
}

int main() {
    int size = 8;
    int Nth;
    int weight = 1;
    cout << "The serial number of fake coin: ";
    cin >> Nth;
    cout << "The weight of fake coin: ";
    cin >> weight;
    int coins[size];
    for(int i = 0; i < size; i++) {
        if(i == Nth - 1){
            coins[i] = weight;
        } else {
            coins[i] = 2;
        }
        cout << coins[i] << "\t";
    }
    cout << endl;
    coin(coins, 0, size - 1);
    return 0;
}
