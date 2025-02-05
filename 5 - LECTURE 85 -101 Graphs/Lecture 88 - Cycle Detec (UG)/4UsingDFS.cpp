#include<bits/stdc++.h>
using namespace std;


bool isCyclicDFS(int srcNode,int parent, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> adj) {

        visited[srcNode]=true;
  
        for(auto neb : adj[srcNode]){
            if(!visited[neb]){
                bool detected = isCyclicDFS(neb, srcNode, visited, adj);
                if(detected) return true;
            }
            else if(parent!= neb && visited[neb]==true){
                return true;
            }
        }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create an adjacancy list 
   unordered_map<int , list<int> > adj;
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int , bool > visited;


    //to handel disconnected componten
    for(int i = 0 ; i< n ; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i , -1, visited , adj );
            if(ans) return "Yes";
        }
    }

    return "No";
}

int main(){

}