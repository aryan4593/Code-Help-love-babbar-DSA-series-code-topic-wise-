
#include <bits/stdc++.h>
using namespace std;
int timer = 0 ;


void dfs (int node , int parent , vector<int>& visited , unordered_map<int, list<int>>& adj,
            vector<int>& tim  , vector<int>& low ,vector<vector<int>>& ans) {

     visited[node]= true;
     tim[node] = timer;
     low[node] = timer;
     timer++;

     for(auto&neb : adj[node]){
         if(neb == parent) continue;
         if(!visited[neb]){
             dfs(neb , node , visited ,adj ,tim , low , ans);

             low[node] = min(low[node] , low [neb]);

            //  can node - neb be a bridge
             if(low [neb] > tim[node]){
                 ans.push_back({neb , node});
             }
         }
         else{

             low[node] = min(low [node] , low [neb]);
         }
     }
}

vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> tim(v, -1);
    vector<int> low(v, -1);
    vector<int> vis(v , 0);

    vector<vector<int>> ans;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i , -1 ,vis ,adj ,tim ,low ,ans);
        }
    }

    return ans;
}
// 