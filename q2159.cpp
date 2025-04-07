#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const long long llong_max = 30000000001;
    const int map_max = 100000; // map is maximum 100000 * 10000

    int dirX[5] = {0, 0, 0, 1, -1};
    int dirY[5] = {0, 1, -1, 0, 0};
    // middle, right, left, down, up
    
    long long dp[100001][5] = {}; 
    // each customer, and reachable 5 places -up, down, right, left, middle- of each customer
    int N; // number of customers
    pair<int, int> customer_location[100001] = {}; // location (x, y) of N customers
    
    cin >> N; 

    int startX, startY; // starts moving at (startX, startY)
    cin >> startX >> startY;

    for (int i = 0; i < N; i++) { // for each customer
        // get the locations of customers
        cin >> customer_location[i].first >> customer_location[i].second;

        for (int j = 0; j < 5; j++) { // for 5 nearest location of each customer
            dp[i][j] = llong_max; 
        }
    }

    for (int j = 0; j < 5; j++) { // for 5 nearest location of first customer
        int nextX = customer_location[0].first + dirX[j];
        int nextY = customer_location[0].second + dirY[j];

        // check if (nextX, nextY) is a valid location on the map
        if (nextX < 1 || nextX > map_max || nextY < 1 || nextY > map_max)
            continue;
        
        long long distance = abs(startX - nextX) + abs(startY - nextY);
        dp[0][j] = distance;
    }

    for (int i = 1; i < N; i++) { // for second ~ Nth customer, do the same thing
        for (int j = 0; j < 5; j++) { // for each 5 directions of the current customer
            int nextX = customer_location[i].first + dirX[j];
            int nextY = customer_location[i].second + dirY[j];

            // check if (nextX, nextY) is a valid location on the map
            if (nextX < 1 || nextX > map_max || nextY < 1 || nextY > map_max)
                continue;
            
            for (int k = 0; k < 5; k++) { // for each 5 directions of the previous customer
                int prevX = customer_location[i-1].first + dirX[k];
                int prevY = customer_location[i-1].second + dirY[k];

                // check if (prevX, prevY) is a valid location on the map
                if (prevX < 1 || prevX > map_max || prevY < 1 || prevY > map_max)
                    continue;
                
                long long distance = abs(prevX - nextX) + abs(prevY - nextY);
                dp[i][j] = min(dp[i][j], dp[i-1][k] + distance); 
                // select the min between current stored value, and previous customer's k location + distance
            }
            
        }
    }

    long long answer = llong_max;

    for (int j = 0; j < 5; j++) { // among 5 possible directions of the last customer, chose the min
        answer = min(dp[N-1][j], answer);
    }

    cout << answer;

    return 0;
}