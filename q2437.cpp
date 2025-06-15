#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> weights(N, 0);
    for(int i = 0; i < N; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    long long k = 1; // the min weight that cannot be checked using the given weights

    for(int i = 0; i < weights.size(); i++) {
        if(weights[i] > k) {
            // k cannot be expressed using the given weights
            break;
        }
        else {
            k += weights[i];
        }
        if(i == weights.size()-1) {
            // all given weights are checked
            break;
        }
    }

    cout << k;

    return 0;
}