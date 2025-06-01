#include <iostream>
using namespace std;

int main(){
    int coins[6] = {500, 100, 50, 10, 5, 1};
    int payed;
    cin >> payed;

    int change = 1000 - payed;

    int num_coins = 0;

    for(int i = 0; i < 6; i++) {
        while (change / coins[i] > 0) {
            change -= coins[i];
            num_coins++;
        }
    }

    cout << num_coins;
    
    return 0;
}