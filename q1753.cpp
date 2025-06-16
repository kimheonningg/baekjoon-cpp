#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(){
    int V, E; // number of vertices and edges
    cin >> V >> E;
    int s; // starting vertex (source)
    cin >> s;
    
    // store edge information
    vector<vector<pair<int, int>>> edges(V+1);
    for (int i = 0 ; i < E; i++) {
        int temp_start, temp_end, temp_weight;
        cin >> temp_start >> temp_end >> temp_weight;
        edges[temp_start].push_back(make_pair(temp_end, temp_weight));
    }

    int INF = 10e8;

    vector<int> cost(V+1, INF);

    // I will use Dijkstra's algorithm since the edges are non-negative

    cost[s] = 0; // cost at starting node is 0
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq; // stores (cost, node)

    pq.push({0, s});

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        int current_cost = current.first; // the cost of the current node
        int current_node = current.second; // current node of interest
        pq.pop();

        for(int i = 0; i < edges[current_node].size(); i++) {
            // for all adjacent vertices of current node
            // do relaxation
            int adj_node = edges[current_node][i].first;
            int adj_cost = edges[current_node][i].second;

            if(cost[adj_node] > adj_cost + current_cost) {
                // relax
                cost[adj_node] = adj_cost + current_cost;
                pq.push(make_pair(cost[adj_node], adj_node));
                // put the adjacent node and corresponding cost as candidates
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        if(cost[i] == INF) cout << "INF" << endl;
        else cout << cost[i] << endl;
    }

    return 0;
}