#include <iostream>
#include <cstring>
#include <random>
using namespace std;

bool Comp(string st1, string st2) {
    default_random_engine e;
    bernoulli_distribution u;
    return u(e);
}

string game(string players[], int k) {
    int num = 1 << k;
    while(num > 1) {
        num = num >> 1;
        for(int i = 0; i < num; i++) {
            if(Comp(players[i + num], players[i]))
                players[i] = players[i + num];
        }
    }
    return players[0];
}

int main() {
    return 0;
}
