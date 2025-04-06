#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int* array = new int[N];
    int* length = new int[N]; // stores answers of subproblems 
    for (int i = 0; i < N; i++) {
        cin >> array[i];
        length[i] = 1;
    }

    for (int i = 1; i < N; i++) {
        int current_element = array[i];
        for(int j = 0; j < i; j++) { // search left
            if(array[j] < current_element) { // subsequence candidate
                if(length[j]+1 > length[i]) {
                    length[i] = length[j] + 1; // update max subsequence length
                }
            }
        }
    }

    // find the longest length
    int max_length = length[0];
    for (int i = 1; i < N; i++) {
        if (max_length < length[i])
            max_length = length[i];
    }

    cout << max_length;

    return 0;
}