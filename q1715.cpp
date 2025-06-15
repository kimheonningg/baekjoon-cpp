#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue <int, vector<int>, greater<int>> card_nums;
    for(int i = 0; i < N; i++) {
        int card_num;
        cin >> card_num;
        card_nums.push(card_num);
    }
    
    int sum = 0;

    while(card_nums.size() > 1) { // until there is one final element
        int small1, small2;
        small1 = card_nums.top();
        card_nums.pop();
        small2 = card_nums.top();
        card_nums.pop();

        sum += small1 + small2;
        card_nums.push(small1+small2);
    }

    cout << sum;

    return 0;
}