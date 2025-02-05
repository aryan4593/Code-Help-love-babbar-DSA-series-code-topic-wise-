#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //.adj matrix
    unordered_map <int , list<int> > adj;
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegrees(v ,0);
    for(auto i : adj ){
        for(auto j : i.second){
            indegrees[j]++;
        }
    }
    
    // push 0 indegrees
    queue<int> q;
    for(int i = 0  ; i < v ; i++){
        if(indegrees[i]==0) q.push(i);
    }

    //do bfs
    vector<int> ans;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        //store ans
        ans.push_back(front);
        // update neb degree
        for(auto neb : adj [front]){
            indegrees[neb]--;
            if(indegrees[neb]==0) q.push(neb);
        }

    }

    return ans;
}

int main(){

    return 0;
}