#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>>& adj, int parent, int& timer, 
         vector<int>& discovery, vector<int>& low, vector<vector<int>>& ans, 
         unordered_map<int, bool>& visited) {
    visited[node] = true;
    discovery[node] = low[node] = ++timer;

    for (auto& neb : adj[node]) {
        if (neb == parent) continue;

        if (!visited[neb]) {
            dfs(neb, adj, node, timer, discovery, low, ans, visited);
            low[node] = min(low[node], low[neb]);

            // Check if the edge is a bridge
            if (low[neb] > discovery[node]) {
                ans.push_back({node, neb});
            }
            
        } else {
            // Update low if already visited
            low[node] = min(low[node], discovery[neb]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (auto& edge : edges) {
        adj[edge[1]].push_back(edge[0]);
        adj[edge[0]].push_back(edge[1]);
    }

    int timer = 0;
    vector<int> discovery(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> visited;

    vector<vector<int>> ans;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, adj, -1, timer, discovery, low, ans, visited);
        }
    }

    return ans;
}