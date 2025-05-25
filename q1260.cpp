#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> edges;
vector<int> DFS_result;
vector<bool> DFS_visited;
vector<int> BFS_result;
vector<bool> BFS_visited;
queue<int> BFS_queue;

void dfs(int s) {
    for (int i = 0; i < edges[s].size(); i++) { // traverse all adjacent vertices of s
        if(!DFS_visited[edges[s][i]]) { // not visited yet
            // visit that vertex
            DFS_visited[edges[s][i]] = true;
            DFS_result.push_back(edges[s][i]);
            dfs(edges[s][i]);
        }
    }
}

void bfs(int s){
    for (int i = 0; i < edges[s].size(); i++) {
        if(!BFS_visited[edges[s][i]]) { // not visited yet
            // visit that vertex
            BFS_visited[edges[s][i]] = true;
            BFS_queue.push(edges[s][i]);
            BFS_result.push_back(edges[s][i]);
        }
    }
    while (!BFS_queue.empty()) {
        int next = BFS_queue.front();
        BFS_queue.pop();
        bfs(next);
    }
}

int main() {
    int N, M, s; // N vertices, M edges, starting vertex s
    cin >> N >> M >> s;

    // store all edge infos
    edges.assign(N+1, vector<int>());
    int tempV1, tempV2;
    for (int i = 0; i < M; i++) { // make the adjacency lists
        cin >> tempV1 >> tempV2;
        edges[tempV1].push_back(tempV2);
        edges[tempV2].push_back(tempV1);
        // since edges are undirectional
    }

    for (int i = 1; i <= N; i++) // sort the adjacency list of each vertex in ascending order
        sort(edges[i].begin(), edges[i].end());

    // do DFS
    DFS_result.clear(); // vector to store DFS-visited results
    DFS_visited.assign(N+1, false); // vector that stores if each vertex is currently visited for DFS
    
    DFS_visited[s] = true;
    DFS_result.push_back(s);
    dfs(s);

    // do BFS
    BFS_result.clear(); // vector to store BFS-visited results
    BFS_visited.assign(N+1, false); // vector that stores if each vertex is currently visited for BFS
    
    BFS_visited[s] = true;
    BFS_result.push_back(s);
    BFS_queue.push(s);    
    bfs(s);

    // print results
    for (int i = 0; i < DFS_result.size(); i++)
        cout << DFS_result[i] << " ";
    
    cout << endl;

    for (int i = 0; i < BFS_result.size(); i++)
        cout << BFS_result[i] << " ";

    return 0;
}