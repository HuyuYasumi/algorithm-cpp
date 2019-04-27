#include <iostream>
#include <set>
using namespace std;

int removeRepeat(int arr[]) {
    set<int> idxs;    //存储需要删除的元素的下标
    int i, j;
    int len = arr[0] + 1;
    for(i = 1; i < len; i++) {
        if(idxs.find(i) == idxs.end()) {
            for(j = i + 1; j < len; j++) {
                if(arr[j] == arr[i]) {
                    idxs.insert(j);
                }
            }
        }
    }
    for(i = 0, j = 1; j < arr[0] + 1; j++) {
        if(idxs.find(j) == idxs.end()) {
            i++;
            arr[i] = arr[j];
        }
    }
    return arr[0] = arr[0] - (j - i - 1);
}

int main() {
    //0号元素代表数组逻辑上的大小
    int arr1[] = {6, 1, 3, 1, 3, 4, 1};
    int arr3[] = {7, 3, 3, 3, 3, 3, 3, 4};
    int arr4[] = {8, 0, 0, 0, 2, 2, 0, 0, 0};
    cout << removeRepeat(arr1) << endl;
    cout << removeRepeat(arr3) << endl;
    cout << removeRepeat(arr4) << endl;
    return 0;
}