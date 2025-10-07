#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int N, K; // N people
    cin >> N >> K;

    queue<int> q;
    // insert N people (1~N) inside the queue
    for (int i = 1; i <= N; i++) q.push(i); 

    cout << "<";

    while (q.size() > 1) {
        for(int i = 1; i < K; i++) {
            // move (K-1) elements infront of the queue to the back of the queue
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front();
    cout << ">\n";

    return 0;
}