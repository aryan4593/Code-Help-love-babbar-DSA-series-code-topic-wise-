#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    void dfs (vector<vector<int>>& adj ,int node ,unordered_map<int , bool > &visited ,stack<int>&st ){
        visited[node]=true;
        for(int neb : adj[node]){
            if(!visited[neb]) dfs(adj , neb , visited , st);
        }
        st.push(node);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int> ans;
        unordered_map<int , bool > visited;
        stack<int> st;
        for(int i = 0  ; i< adj.size(); i++){
            if(!visited[i]) dfs(adj , i , visited ,st);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};