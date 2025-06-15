#include <iostream>
using namespace std;

int main() {
    int T, N, M;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        int* coins = new int[N+1];
        for(int i = 1; i <= N; i++) cin >> coins[i];
        cin >> M;
        int* methods = new int[M+1]; // methods[i] is number of methods to make value i

        methods[0] = 1;
        for (int i = 1; i <= N; i++) { // coin types
            for(int j = coins[i]; j <= M; j++) { // values
                methods[j] += methods[j-coins[i]];
            }
        }

        cout << methods[M] << endl;
    }

    return 0;
}