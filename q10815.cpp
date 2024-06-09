#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, M, temp;
    cin >> N;

    set<int> cards;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        cards.insert(temp);
    }
    
    cin >> M;

    int* answer = new int[M];
    for(int i = 0; i < M; i++) {
        cin >> temp;
        if(cards.find(temp) != cards.end())
            answer[i] = 1;
        else
            answer[i] = 0;
    }

    for(int i = 0; i < M; i++)
        cout << answer[i] << " ";
    
    // delete answer
    delete[] answer;
    answer = nullptr; 

    return 0;
}