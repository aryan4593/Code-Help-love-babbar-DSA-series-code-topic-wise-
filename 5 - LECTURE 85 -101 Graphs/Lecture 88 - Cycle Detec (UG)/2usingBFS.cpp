#include<bits/stdc++.h>
#include<iostream>
using namespace std;


bool isCyclicBFS (int srcNode ,  unordered_map<int , bool > &visited ,
                    unordered_map<int , list<int> > adj){

    unordered_map<int , int> parent;
    parent[srcNode] = -1;
    visited[srcNode] = true;
    queue<int> q;
    q.push(srcNode);


    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto &neb : adj[front]){
            if (neb != parent[front] && visited[neb] ) {
                return  true;
            }
            else if (!visited[neb]){
                q.push(neb);
                visited[neb]=true;
                parent[neb]=front;
            }
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
            bool ans = isCyclicBFS(i , visited , adj );
            if(ans) return "Yes";
        }
    }

    return "No";
}


int main() {
    // Test case 1: Graph with a cycle
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    int n1 = 3, m1 = 3;
    cout << "Test case 1 - Expected: Yes, Got: " << cycleDetection(edges1, n1, m1) << endl;

    // Test case 2: Graph without a cycle
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}};
    int n2 = 4, m2 = 3;
    cout << "Test case 2 - Expected: No, Got: " << cycleDetection(edges2, n2, m2) << endl;

    // Test case 3: Disconnected graph with a cycle in one component
    vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};
    int n3 = 5, m3 = 4;
    cout << "Test case 3 - Expected: Yes, Got: " << cycleDetection(edges3, n3, m3) << endl;

    // Test case 4: Disconnected graph without any cycle
    vector<vector<int>> edges4 = {{0, 1}, {2, 3}};
    int n4 = 4, m4 = 2;
    cout << "Test case 4 - Expected: No, Got: " << cycleDetection(edges4, n4, m4) << endl;

    return 0;
}