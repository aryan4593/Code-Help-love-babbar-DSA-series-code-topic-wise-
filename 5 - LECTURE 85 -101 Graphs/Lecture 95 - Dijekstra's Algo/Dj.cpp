#include<bits/stdc++.h>
using namespace std;
////using set

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i = 0 ; i < edges ;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        adj[u].push_back({v,  wt});
        adj[v].push_back({u,  wt});
    }

    vector<int> distance(vertices , INT_MAX);
    set<pair<int,int>> sett; //dist, v;

    distance[source]= 0;

    sett.insert({0 , source});

    while(!sett.empty()){
        auto top = *(sett.begin());
        sett.erase(sett.begin());
        int dist = top.first;
        int topNode = top.second;

        for(auto&neb : adj[topNode]){
            int nebWt = neb.second;
            int nebNode = neb.first;

            if(dist + nebWt < distance[nebNode]){
                auto record = sett.find({distance[nebNode] , nebNode}); // if record already exists means not int max

                if(record != sett.end()) sett.erase(record);

                distance[nebNode] = dist + nebWt;
                sett.insert({distance[nebNode] , nebNode});
            }
        }
    }

    return distance;
}

int main(){
    return 0;
}