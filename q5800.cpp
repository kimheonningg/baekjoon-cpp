#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int K, N;
    cin >> K;

    for(int i = 0; i < K; i++) {
        cin >> N;

        int tempScore;
        int minScore = 100;
        int maxScore = 0;
        vector<int> scores;

        for(int j = 0; j < N; j++) {
            cin >> tempScore;
            scores.push_back(tempScore);
            if(minScore > tempScore)
                minScore = tempScore;
            if(maxScore < tempScore)
                maxScore = tempScore;
        }

        sort(scores.begin(), scores.end());
        int largestGap = 0;
        for(int j = 0; j < scores.size()-1; j++) {
            int gap = scores[j+1] - scores[j];
            if(largestGap < gap)
                largestGap = gap;
        }

        cout << "Class " << (i+1) << endl;
        cout << "Max " << maxScore << ", Min " << minScore << ", Largest gap " << largestGap << endl;
    }

    return 0;
}