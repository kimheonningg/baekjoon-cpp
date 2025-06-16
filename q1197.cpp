#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> edge_infos(V+1);
    vector<bool> visited(V+1);
    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edge_infos[A].push_back(make_pair(C, B));
        edge_infos[B].push_back(make_pair(C, A));
    }

    // I will use Prim's algorithm

    int cost = 0;
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > edges; 
    // used to store the candidates for the min-cost edge

    edges.push({0, 1}); // start with node 1, cost 0

    while(!edges.empty()) { // while every vertex is included in the final solution
        pair<int, int> min_edge = edges.top();
        edges.pop();

        int new_cost = min_edge.first;
        int new_index = min_edge.second;

        if(visited[new_index]) continue;
        cost += new_cost;
        visited[new_index] = true;

        for(auto &[next_cost, next_index] : edge_infos[new_index]) {
            edges.push({next_cost, next_index});
        }
    }

    cout << cost;

    return 0;
}