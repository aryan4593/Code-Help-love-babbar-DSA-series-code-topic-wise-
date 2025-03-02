#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> ans;
        
        vector<int> dist(V , 1e8);
        
        dist[src] = 0;
        
        for(int i = 0 ; i < V-1 ;i++){
            //  traverse all edges
            
            for(auto&edge : edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u]!=1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // traverse once more to get negative cycle
            for(auto&edge : edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u]!=1e8 && dist[u] + wt < dist[v]){
                    // if dist get updated means negative cycle exist
                    return {-1};
                }
            }
            
        return dist;
        
    }
};