#include <iostream>
using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;
    // N * M map, C number of arcades

    int map[51][51] = {0}; // max is 50 * 50 map
    int dp[51][51][51][51] = {0}; 
    // [r][c][max number of arcade already stopped by][number of arcades stopped by] 
    // (r, c) is the coordinate

    // store the locations of arcades
    for (int i = 1; i <= C; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = i;
    }

    if (map[1][1] == 0) // no arcade at the starting point
        dp[1][1][0][0] = 1; // since he stopped by at 0 arcades at the start 
    else // an arcade is located at the starting point
        dp[1][1][map[1][1]][1] = 1; // since he stopped by at one arcade - arcade number map[1][1]
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if(i == 1 && j == 1) continue; // starting case

            int current_location = map[i][j]; // 0 if no arcade, arcade number if arcade exists

            if(current_location == 0) { // currently there is no arcade
                for (int y = 0; y <= C; y++) {
                    for (int x = 0; x <= C; x++) {
                        dp[i][j][x][y] += (dp[i-1][j][x][y] + dp[i][j-1][x][y]) % 1000007; 
                        // when moving up->down, and when moving left->right
                    }
                }
            }
            else { // curently there is an arcade
                for (int y = 1; y <= C; y++) {
                    for (int x = 0; x <= current_location; x++) {
                        dp[i][j][current_location][y] += (dp[i-1][j][x][y-1] + dp[i][j-1][x][y-1]) % 1000007;
                    }
                }
            }
        }
    }

    // print based on the number of arcades he stopped by, which is the 4th element of the array
    for (int y = 0; y <= C; y++) { // y is the number of arcades he stopped by
        int num = 0;
        for (int x = 0; x <= C; x++) { // for every path at (N, M) with y stopped by arcades
            num += dp[N][M][x][y] % 1000007;
        }
        cout << num % 1000007 << " ";
    }

    return 0;
}