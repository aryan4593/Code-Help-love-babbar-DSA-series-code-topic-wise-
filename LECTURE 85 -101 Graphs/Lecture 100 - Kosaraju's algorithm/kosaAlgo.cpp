
#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>

void dfs(int node , unordered_map<int , list <int>> &adj, vec &visited , stack<int>&topo,
        bool flag){
    visited[node] = true;
    
    for(auto&neb : adj[node]){
        if(!visited[neb]) {
            dfs(neb , adj , visited, topo, flag);
        }
    }
    
    if(flag) //as we've to reuse dfs, where we don't need any stack operation
       topo.push(node);
}

int stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
	unordered_map<int , list <int>> adj;
        for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
       stack<int>topo;
       vec visited(V, 0);
        
       for(int i = 0; i < V ; i++){
           if(!visited[i]) dfs(i , adj , visited , topo ,true) ;
       }
       
    //   trnspose graph
        unordered_map<int , list <int>> transpose;
        for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            transpose[v].push_back(u);
            
        }
        
         fill(visited.begin(), visited.end(), 0);
         
        int count = 0 ;
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();
            
            if(!visited[top]){
                count++;
                dfs(top , transpose ,visited,topo,false);
            }
        }
        
        return count;
}
int main()
{
    // Solution s1;
    vector<vec> v1 = {
        {1, 0},
        {0, 2},
        {2, 1},
        {0, 3},
        {3, 4}};
    // cout<<s1.kosaraju(5, v1);
}