#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int wt){
        pair<int, int> pairr = make_pair(v, wt);
        adj[u].push_back(pairr);
    }
    void printAdj(){
        for (auto &i : adj){
            cout << i.first << " -> ";
            for (auto &j : i.second){
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    void dfs(unordered_map<int , bool> &visited ,stack<int> &st, int node){
        visited[node]=true;

        for(auto neb : adj[node]){
            if(!visited[neb.first]){
                dfs(visited , st , neb.first);
            }
        }
        st.push(node);
    }


    void getShortestPath(int src  , vector<int> &dist , stack<int> &topo ){
        dist[src]=0;

        while(!topo.empty()){
            int top = topo.top();
            topo.pop();
            if(dist[top] != INT_MAX){
                //PROCESS
                for(auto &i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top]+i.second; 
                    }
                }
            }
        }
    }
};



int main(){
    Graph g;
    g.addEdge(0 , 1 ,5);
    g.addEdge(0 , 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.printAdj();

    //topo sort 
    int n = 6;
    unordered_map<int , bool> visited;
    stack<int> st;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]) g.dfs( visited ,st ,i);
    }

    int src = 1;
    vector<int> dist(n);
    for(int i = 0 ; i<n;i++){
        dist[i] = INT_MAX;
    }
    dist[src]=0;

    g.getShortestPath(src ,dist , st);

    cout<<"Answer is: ";
    for(auto dis : dist){
        cout<<dis<<" ";
    }cout<<endl;

} 