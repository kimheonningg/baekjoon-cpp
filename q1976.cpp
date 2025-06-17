#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dfs_call_count;
vector<vector<int>> edges;
bool* visited;
int* plan;

void dfs(int x) {
    visited[x] = true;
    for(int i = 0; i < edges[x].size(); i++)
        if(!visited[edges[x][i]]) dfs(edges[x][i]);
}

int main() {
    cin >> N;
    cin >> M;

    dfs_call_count = 0;
    edges.resize(N+1);
    visited = new bool[N+1];
    plan = new int[M];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int connected;
            cin >> connected;
            if(connected == 1) { // connected
                edges[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < M; i++) {
        int visit_plan;
        cin >> visit_plan;
        if(!visited[visit_plan]) {
            dfs_call_count ++; 
            // dfs must be called once to visit all cities at once
            dfs(visit_plan);
        }
    }

    if(dfs_call_count == 1) cout << "YES";
	else cout << "NO";

    return 0;
}