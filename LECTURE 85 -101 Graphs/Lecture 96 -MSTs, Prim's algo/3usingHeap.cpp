#include <bits/stdc++.h> 
using namespace std;
#define P pair<int,int>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int ,list<P>> adj;
    for(auto&graph : g){
        int u = graph.first.first;
        int v = graph.first.second;
        int wt = graph.second;

        adj[u].push_back({v , wt});
        adj[v].push_back({u, wt});
    }

    vector<int> visited(n+1 , 0 );
    vector<int> parent (n+1 , -1);
    vector<int> weights(n+1 , INT_MAX);

    priority_queue< P , vector<P> , greater<P>> pq;  // wt , u 

    pq.push({0 , 1});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if(visited[node]) continue;

        visited[node] = true;

        for(auto neb : adj[node]){
            int adjNode = neb.first;
            int wtOfAdj = neb.second;

            if(!visited[adjNode] && wtOfAdj < weights[adjNode]) {
                parent[adjNode] = node;
                pq.push({wtOfAdj ,  adjNode});
                weights[adjNode] = wtOfAdj;
            }

        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for(int i = 2 ; i < n+1 ; i++){
        // auto nodes = ;
        ans.push_back({{parent[i] ,i} , weights[i]});
    }

    return ans;

}
int main(){
    return 0;
}