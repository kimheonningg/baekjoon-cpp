#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int* soldiers = new int[N];
    int* length = new int[N]; // max length of subarray
    for (int i = 0; i < N; i++) {
        cin >> soldiers[i];
        length[i] = 1;
    }

    for (int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(soldiers[j] > soldiers[i]) {
                if(length[j] + 1 > length[i])
                    length[i] = length[j] + 1;
            }
        }
    }

    int max_length = length[0];

    for (int i = 1; i < N; i++)
        if(max_length < length[i])
            max_length = length[i];
    
    cout << (N - max_length);
    
    return 0;
}