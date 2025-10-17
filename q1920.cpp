#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N;
    int* numbers = new int[N];
    for(int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers, numbers+N); // sort in ascending order

    cin >> M;
    for(int i = 0; i < M; i++) {
        // for all M keys, perform binary search
        int key;
        cin >> key;
        
        // binary search through numbers array
        int startIdx = 0;
        int endIdx = N-1;

        bool answerFound = false;

        while (startIdx <= endIdx) {
            int midIdx = (startIdx + endIdx) / 2;
            if(key == numbers[midIdx]) {
                answerFound = true;
                break;
            }
            else if(key < numbers[midIdx]) {
                // search left
                endIdx = midIdx - 1;
            }
            else {
                // key > numbers[midIdx]
                // search right
                startIdx = midIdx + 1;
            }
        }

        cout << (answerFound ? 1 : 0) << '\n';
    }
    return 0;
}