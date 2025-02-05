#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, unordered_map<int, list<pair<int, int>>>& adj, unordered_map<int, bool>& visited, stack<int>& topo) {
        visited[node] = true;
        for (auto& neb : adj[node]) {
            int v = neb.first;
            if (!visited[v]) {
                dfs(v, adj, visited, topo);
            }
        }
        topo.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int, list<pair<int, int>>> adj;
        
        // Build adjacency list
        for (auto& iter : edges) {
            int u = iter[0];
            int v = iter[1];
            int wt = iter[2];
            adj[u].push_back({v, wt});
        }
        
        stack<int> st;
        unordered_map<int, bool> visited;
        
        // Topological sorting
        for (int i = 0; i < V; i++) {
            if (!visited[i] && adj.find(i) != adj.end()) {
                dfs(i, adj, visited, st);
            }
        }
        
        // Initialize distances
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        // Relax edges in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (dist[node] != INT_MAX) { // Only process reachable nodes
                for (auto& it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        // Replace unreachable nodes with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
