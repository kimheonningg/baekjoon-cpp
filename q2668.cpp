#include <iostream>
#include <vector>
using namespace std;

int N;
int* edges;
bool* visited;
vector<int> answer; // number of edges inside all cycles

void dfs(int current, int start){
    if(visited[current]) {
        // check if this node makes a cycle
        if(start == current) // it is a cycle
            answer.push_back(current);
        return;
    }

    visited[current] = true;
    dfs(edges[current], start); 
    // check the connected edges to see if it forms a cycle
}

int main() {
    cin >> N;
    edges = new int[N+1];
    visited = new bool[N+1];
    for (int i = 1; i <= N; i++)
        cin >> edges[i]; // edge connected to i

    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            visited[j] = false; // initialize visited array
        dfs(i, i);
    }

    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

    return 0;
}