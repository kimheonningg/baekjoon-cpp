#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int N, M;
    string temp;
    cin >> N >> M;

    set<string> words;
    int answer = 0;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        words.insert(temp);
    }

    for(int i = 0; i < M; i++) {
        cin >> temp;
        if(words.find(temp) != words.end())
            answer++;
    }

    cout << answer;

    return 0;
}