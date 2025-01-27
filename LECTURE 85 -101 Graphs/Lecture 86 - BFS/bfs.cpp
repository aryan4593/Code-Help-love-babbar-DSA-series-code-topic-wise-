#include<bits/stdc++.h>
using namespace std;

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto i : adj[front]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Start BFS from vertex 0, since we need to visit all nodes connected to vertex 0
    if (!visited[0]) {
        bfs(adj, visited, ans, 0);
    }

    return ans; 
}
