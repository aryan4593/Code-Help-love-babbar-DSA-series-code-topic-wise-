#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	//do bfs and find parent of all node
	//create a adj list
	unordered_map<int , list<int>> adj;
	for(int i = 0 ; i < edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int , bool > visited;
	unordered_map<int , int > parent;
	queue<int> q;
	q.push(s); //source nnode
	visited[s]=true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto neb : adj[front]){
			if(!visited[neb]){
				visited[neb]=true;
				q.push(neb);
				parent[neb]=front;
			}
		}
	}

	//backtrack
  vector<int> ans;

        int currNode = t;
        while (currNode != s) {
            ans.push_back(currNode);
            currNode = parent[currNode];
        }
        ans.push_back(s); 
        reverse(ans.begin(), ans.end()); 
	return  ans ;
}
