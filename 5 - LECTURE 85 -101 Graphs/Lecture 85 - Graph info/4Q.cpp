#include<iostream>
using namespace std;
#include<vector>


vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(n); // Properly declare the adjacency list

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        adjList[i].insert(adjList[i].begin(), i); 
    }

    return adjList; // Return the adjacency list
}