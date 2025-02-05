#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
class Solution {
    
    void dfs(int &node , int parent , vec adj[], vec &visited , vec &disc, vec &low , int &timer,
             set<int> &ans){
                 
        visited [node]  = true;
        disc[node] = low [node] = timer++;
        
        int child = 0;
        
        for(auto&neb : adj[node]){
            if(neb == parent) continue;
            
            if(!visited[neb]){
                dfs(neb , node , adj , visited , disc , low , timer , ans);
                low[node ]  = min (low [node] , low [neb]);
                
                //checck art. point
                
                if(low[neb] >= disc[node] && parent!= -1){
                    ans.insert(node);
                }
                child++;
            }
            
            else{
                low [node] = min(low [node] , disc[neb]);
            }
        }
        
        if(parent==-1 && child > 1){
            ans.insert(node);
        }
                 
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        set<int> ans;
        
        int timer = 0;
        vector<int> disc(V , -1);
        vector<int> low (V , -1);
        
        vector<int> visited(V , 0);
        
        // dfs
        
        for(int i = 0 ; i < V ; i ++){
            if(!visited[i]){
                dfs(i , -1 , adj , visited ,disc , low  , timer ,ans);
            }
        }
        
        if(ans.empty()) return {-1};
        vector<int> result;
        for(auto&i : ans){
            result.push_back(i);
        }
        
        return result;
        
    }
};
