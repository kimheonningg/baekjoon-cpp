#include <iostream>
#include <deque>
using namespace std;

/*
    Defined operations

    - Operation 1: perform pop_front
    - Operation 2: perform pop_front & push_back the popped element
    - Operation 3: perform pop_back & push_front the popped element
*/

int main() {
    int N, M;
    cin >> N >> M;

    // create numbers of 1~N
    deque<int> numbers;
    for(int i = 1; i <= N; i++)
        numbers.push_back(i);

    int answer = 0; // number of operations 2 & 3 used

    for (int i = 0; i < M; i++) {
        int target; // current target to pop_front
        cin >> target;

        int target_idx;
        // find the index where the target is located
        for (int i = 0; i < numbers.size(); i++)
            if(numbers[i] == target) {
                target_idx = i;
                break;
            }

        // decide the direction to rotate- right or left
        if(target_idx <= numbers.size() / 2) {
            // better to rotate left (operation 2), or operation 1 if target is at front
            while (true) {
                if(numbers.front() == target) {
                    // operation 1
                    numbers.pop_front();
                    break;
                }
                // operation 2
                answer ++;
                numbers.push_back(numbers.front());
                numbers.pop_front();
            }
        }
        else { // target_idx > numbers.size() / 2
            // better to rotate right (operation 3), or operation 1 if target is at front
            while(true) {
                if(numbers.front() == target) {
                    // operation 1
                    numbers.pop_front();
                    break;
                }
                // operation 3
                answer ++;
                numbers.push_front(numbers.back());
                numbers.pop_back();
            }
        }
    }

    cout << answer;

    return 0;
}