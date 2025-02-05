#include<bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 0;

    void dfs(int node , int parent , unordered_map<int , list<int>> &adj ,vector<int>&visited,
             vector<int>&low , vector<int>&tim , vector<vector<int>>&ans){

      visited[node] = true;
      tim [node] = timer;
      low [node] = timer;
      timer++;

      for(auto&neb:adj[node]){
        if(neb == parent ) continue;

        if(!visited[neb]){
            dfs(neb , node , adj ,visited  , low , tim  , ans);

            low [node] = min(low [node] ,  low [neb]);
            // is node -- neb a bridge??

            if(low[neb] > tim[node]){
                ans.push_back({node , neb});
            }
        }
        else{
            low [node] =  min(low[node] , low[neb]);
        }
      }
}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int , list<int>> adj;

        for(auto& conn : connections){
            int u = conn[0];
            int v = conn[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n , 0);
        vector<int> low (n , -1);
        vector<int> tim (n , -1);

        int parent = -1;
        vector<vector<int>> ans;
        dfs(0 , parent , adj ,visited ,low , tim , ans);
        return ans;
    }   
};