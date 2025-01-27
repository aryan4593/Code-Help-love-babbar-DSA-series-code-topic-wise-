#include<bits/stdc++.h>
using namespace std;

#define P pair<int , int>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int , list<P>> adj;
        // adjacency list
        for(int i = 0 ; i < points.size() ; i++){
            auto pt1 = points[i];
            for(int j = i ; j < points.size() ; j++){
                auto pt2 = points[j];

                int dist = abs(pt1[0] - pt2[0]) + abs (pt1[1] - pt2[1]);
                adj[i].push_back({j , dist});
                adj[j].push_back({i , dist});
            }
        }

        priority_queue<P , vector<P> , greater<P>> pq; // dist , node
        vector<int> visited(n , 0);
        pq.push({0 , 0});

        int sum = 0 ;

        while(!pq.empty()){
            P iter = pq.top(); 
            pq.pop();
            int wt  = iter.first;
            int node = iter.second;

            if(visited[node]) continue;

            sum+=wt;
            visited[node] = true;

            for(auto&it : adj [node]){
                int adjNode = it.first ;
                int adjWt = it.second;

                if(!visited[adjNode] ) pq.push ( {adjWt , adjNode});
            }
        }

        return sum;
    }
};