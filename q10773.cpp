#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K, num;
    cin >> K;

    stack<int> money;

    for(int i = 0; i < K; i++) {
        cin >> num;

        if(num == 0) { money.pop(); }
        else { money.push(num); }
    }

    int sum = 0;

    while(!money.empty()){
        sum += money.top();
        money.pop();
    }

    cout << sum;

    return 0;
}