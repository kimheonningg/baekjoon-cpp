#include <iostream>
using namespace std;

int main() {
    int N, K; // N number of items and max weight K
    cin >> N >> K;

    int* W = new int[N+1]; // weight of each item
    int* V = new int[N+1]; // value of each item

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];
    
    int** dp = new int*[N+1];
    for (int i = 0; i <= N; i++) 
        dp[i] = new int[K+1];
    // dp[i, j] stores the max value of items 1~i with weight j

    // value = 0 for 0 items or with 0 weight
    for(int i = 0; i <= N; i++) dp[i][0] = 0;
    for(int j = 0; j <= K; j++) dp[0][j] = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if (W[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], V[i]+dp[i-1][j-W[i]]);
        }
    }

    cout << dp[N][K];    

    return 0;
}