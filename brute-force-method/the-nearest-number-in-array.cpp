#include <iostream>
#include <cmath>
#define ARR_SIZE 5
using namespace std;

int nearest_num(int arr[], int len);

int main() {
    int arr[ARR_SIZE] = {0, 0, 0, 0, 0};
    cout << "Enter five integers: ";
    for(int i = 0; i < ARR_SIZE; i++) {
        cin >> arr[i];
    }
    cout << nearest_num(arr, 5);
    return 0;
}

int nearest_num(int arr[], int len) {
    int m = 0, n;
    int min = abs(arr[0] - arr[1]);
    while(m < len) {
        n = m + 1;
        while(n < len) {
            int dis = abs(arr[m] - arr[n]);
            if(min > dis) {
                int tmp = dis;
                dis = min;
                min = tmp;
            }
            n++;
        }
        m++;
    }
    return min;
}