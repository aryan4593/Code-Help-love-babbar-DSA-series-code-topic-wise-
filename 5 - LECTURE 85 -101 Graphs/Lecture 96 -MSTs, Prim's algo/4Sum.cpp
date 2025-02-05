#include<bits/stdc++.h>
using namespace std;

#define P pair<int,int>
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> visited(V , 0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(visited[node]) continue; //no need to do anything;
            visited[node] = true;
            sum+=wt;
            for(auto&it : adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                
                if(!visited[adjNode]) 
                    pq.push({edgeWt , adjNode});
            }
        }
        return sum;
    }
};