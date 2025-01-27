#include <bits/stdc++.h>
using namespace std;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  int e = edges.size();
  int v = n;
 unordered_map <int , list<int> > adj;
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

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
    int count = 0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        //store ans
        count++;
        // update neb degree
        for(auto neb : adj [front]){
            indegrees[neb]--;
            if(indegrees[neb]==0) q.push(neb);
        }

    }
//
    return count != n;
}