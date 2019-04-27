#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool prefect_num(int n_num);

int main() {
    string n_num;
    cout << prefect_num(6) << endl;
    cout << prefect_num(496) << endl;
    cout << prefect_num(8128) << endl;
    cout << "enter a natural number: ";
    cin >> n_num;
    cout << prefect_num(stoi(n_num));
    return 0;
}

bool prefect_num(int n_num) {
    int n = 2;
    vector<int> true_f;
    true_f.push_back(1);
    while(n < n_num) {
        if(find(true_f.begin(), true_f.end(), n) == true_f.end()) {
            int quotient = n_num / n;
            if(n_num % n == 0) {
                true_f.push_back(n);
                true_f.push_back(quotient);
            }
        }
        n++;
    }
    return accumulate(true_f.begin(), true_f.end(), 0) == n_num;
}