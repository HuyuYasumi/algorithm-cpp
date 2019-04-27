#include <iostream>
using namespace std;

int removeIt(int arr[], const int& x) {
    int i, j;
    for(i = 0, j = 1; j < arr[0] + 1; j++) {
        if(arr[j] != x) {
            i++;
            arr[i] = arr[j];
        }
    }
    return arr[0] = arr[0] - (j - i - 1);
}

int main() {
    //0号元素代表数组逻辑上的大小
    int arr1[] = {5, 1, 2, 3, 2, 1};
    int arr2[] = {4, 3, 3, 3, 3};
    int arr3[] = {7, 3, 3, 3, 3, 3, 3, 4};
    int arr4[] = {8, 7, 3, 0, 2, 5, 4, 6, 1};
    int arr5[] = {0};
    cout << removeIt(arr1, 2) << endl;
    cout << removeIt(arr2, 3) << endl;
    cout << removeIt(arr3, 3) << endl;
    cout << removeIt(arr4, 7) << endl;
    cout << removeIt(arr5, 7) << endl;
    return 0;
}