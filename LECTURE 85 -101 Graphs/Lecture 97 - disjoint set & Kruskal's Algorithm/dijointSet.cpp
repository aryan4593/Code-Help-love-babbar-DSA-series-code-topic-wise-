#include <bits/stdc++.h>
using namespace std;

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

int main(){
    disjoint_set ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // check 3 and 7 

    if(ds.findUPar(3) == ds.findUPar(7)) cout<<"same"<<endl;
    else cout<<"Different"<<endl;
    ds.unionByRank(3,7);
    if(ds.findUPar(3) == ds.findUPar(7)) cout<<"same"<<endl;
    else cout<<"Different"<<endl;
    ds.unionByRank(1,2);
    ds.unionByRank(1,2);

}