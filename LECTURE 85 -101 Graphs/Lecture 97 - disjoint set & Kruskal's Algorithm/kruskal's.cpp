#include<bits/stdc++.h>
using namespace std;
#define P pair<int, int>

class disjoint_set{
    vector<int> rank, parent ,size;

public:
    disjoint_set(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1 ,1);

        for (int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]); //to save it 
    }

    void unionByRank(int u , int v ){
        int ultParOfU  =  findUPar(u);
        int ultParOfV  =  findUPar(v);

        if(ultParOfU == ultParOfV) return; ///belong to same component

        else if(ultParOfU < ultParOfV){
            parent[ultParOfU] = ultParOfV; //smaller will get attach to bigger
        }
        else if (ultParOfV < ultParOfU){
            parent[ultParOfV] = ultParOfU;
        }
        else{
            //same rank
            parent[ultParOfV] = ultParOfU; //attach to anyone
            rank[ultParOfU] ++;
        }
    }
    void unionBySize(int u , int v ){
        int ultParOfU  =  findUPar(u);
        int ultParOfV  =  findUPar(v);
        if(ultParOfU == ultParOfV) return; ///belong to same component

        if(size[ultParOfU] < size[ultParOfV]){
            parent[ultParOfV] = ultParOfU;
            size[ultParOfV]+=size[ultParOfU];
        }
        else{
            parent[ultParOfU] = ultParOfV;
            size[ultParOfU]+=size[ultParOfV];
        }
    }
};



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int  , P> > edges;
        
        for(int i =0 ; i < V ;i++){
            for(auto&it : adj[i]){
                int node = i ;
                int adjNode = it[0];
                int wt = it[1];
                
                edges.push_back({wt , {node ,  adjNode}});
            }
        }
        
        sort(edges.begin() , edges.end());
        
        int mstWt = 0;
        disjoint_set ds(V);
        
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWt += wt ; //don't belong to same componoent
                ds.unionBySize(u , v);
            }
        }
        
        
        return mstWt;
                // code here
    }
};
int main() {
    cout<<"aryan"<<endl;
    return 0;
}

// sort all the edges according to weights 