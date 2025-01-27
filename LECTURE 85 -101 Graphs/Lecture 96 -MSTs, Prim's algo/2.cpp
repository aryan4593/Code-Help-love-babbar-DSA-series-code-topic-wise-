#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Create adjacency list
    unordered_map<int, list<P>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // Initialize key, mst, and parent
    vector<int> key(n + 1, INT_MAX); // 1-indexed
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Start from the 1st node
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++) { // Loop n-1 times for n nodes
        int mini = INT_MAX, u = -1;

        // Find the minimum key node which is not in MST
        for (int v = 1; v <= n; v++) {
            if (!mst[v] && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        // Mark the node as part of MST
        if (u == -1) break; // Handle disconnected graphs
        mst[u] = true;

        // Update adjacent nodes
        for (auto &it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if (!mst[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // Prepare the result
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++) {
        if (parent[i] != -1) { // Ignore disconnected nodes
            ans.push_back({{parent[i], i}, key[i]});
        }
    }

    return ans;
}
