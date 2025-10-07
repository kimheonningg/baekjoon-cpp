#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> cards;

    int N; // N cards
    cin >> N;
    
    // insert all cards in ascending order
    for (int i = 1; i <= N; i++) cards.push(i);

    while(cards.size() != 1) {
        cards.pop(); // throw away card at top
        cards.push(cards.front()); // put the card at top at the back
        cards.pop();
    }

    // one card left
    cout << cards.front();

    return 0;
}