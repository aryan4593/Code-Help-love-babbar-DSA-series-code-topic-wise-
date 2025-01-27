#include <bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited,
                   unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> adj){

  visited[node] = true;
  dfsVisited[node] = true;
  for (auto neb : adj[node]){

    if (!visited[neb]){
      
      bool cycleDetedted = checkCycleDFS(neb, visited, dfsVisited, adj);
      if (cycleDetedted)
        return true;
    }

    else if (dfsVisited[neb] == true) return true;
  }
  dfsVisited[node] = false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges){
  // create an adj list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }
  // call dfs for all comp
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  for (int i = 0; i < n; i++){
    if (!visited[i]){
      bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
      if (cycleFound)
        return 1;
    }
  }
  return 0;
}
int main(){

  return 0;
}