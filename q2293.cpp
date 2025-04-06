#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int* coins = new int[n];
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    
    int* methods = new int[k+1]; // to use indices 1 ~ k
    methods[0] = 1;
    for(int j = 1; j <= k; j++)
        methods[j] = 0;

    for(int i = 0; i < n; i++ ){
        for(int j = 0; j <= k; j++) {
            if(j < coins[i]) continue;
            methods[j] = methods[j] + methods[j-coins[i]];
        }
    }

    cout << methods[k];

    return 0;
}