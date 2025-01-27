#include<bits/stdc++.h>
using namespace std;

#define P pair<int, int>
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int vertices = adj.size();
        
        vector<int> distance(vertices , INT_MAX);
        priority_queue<P, vector<P> , greater<P>> minHeap; //dist , node;
        minHeap.push({0 , src});
        distance[src] =0;
        
        while(!minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();
            int node = top.second;
            int dist = top.first;
            
            for(auto&neb : adj[node]){
                int nebNode = neb.first;
                int weight = neb.second;
                
                if(weight + dist < distance[nebNode]){
                    
                    distance[nebNode] =  weight + dist;
                    minHeap.push({distance[nebNode] , nebNode});
                }
            }
        }
        
        return distance;
    }
};

int main(){
    return 0;
}