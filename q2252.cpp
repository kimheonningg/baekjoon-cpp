#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges(N+1, vector<int>(0,0));
    vector<int> in_degree(N+1, 0);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        // A must be infront of B
        edges[A].push_back(B);
        in_degree[B]++;
    }

    // I will use topological sorting

    queue<int> q;
    // insert vertices with in degree 0 inside the queue
    // these vertices have no predecessors
    for(int i = 1; i <= N; i++)
        if(in_degree[i] == 0)
            q.push(i);
    
    while(!q.empty()) {
        int current_node = q.front();
        q.pop();
        cout << current_node << ' ';

        for(int i = 0; i < edges[current_node].size(); i++) {
            in_degree[edges[current_node][i]] -= 1; 
            // remove the edges connected to the current node
            if(in_degree[edges[current_node][i]] == 0) 
                q.push(edges[current_node][i]);
        }
    }

    return 0;
}