#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> numArr(N);
    map<int, int> numMap; // { number, number of number }
    int sum = 0;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        numArr[i] = temp;
        if(numMap.find(temp) != numMap.end()) { // found
            numMap[temp]++;
        }
        else { // not found
            numMap.insert({temp, 0});
        }
    }
    
    double rawAvg = sum / (double)N;
    int avg = round(rawAvg);
    cout << avg << endl; // print average

    sort(numArr.begin(), numArr.end());
    
    int median = numArr[N/2];
    cout << median << endl; // print median

    int mode = numMap.begin()->first;
    int modeCount = numMap.begin()->second;
    for(const auto& numPair : numMap) {
        if(modeCount < numPair.second) {
            mode = numPair.first;
            modeCount = numPair.second;
        }
    }

    // check if there are more than one modes
    for(const auto& numPair : numMap) {
        if(numPair.second == modeCount && numPair.first != mode) {
            mode = numPair.first;
            break;
        }
    }
    
    cout << mode << endl; // print mode

    int minVal = numArr[0];
    int maxVal = numArr[N-1];
    cout << maxVal-minVal << endl; // print range

    return 0;
}