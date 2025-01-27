#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
using namespace std;
 
template<typename T>
class graph {
    public:
        unordered_map < T , list<T> > adj;

        void addEdge(T u , T v , bool direction){
            // direc -> 0 means und graph 1 means directed graph
            // create an edge from u to v 
            adj[u].push_back(v);
            if(!direction) 
                adj[v].push_back(u);
        }
        
        void printAdjList (){
            for(auto i : adj){
                cout<<i.first <<"->";
                for(auto j : i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
             }
        }
};

int main(){
    cout<<"Enter the number of nodes "<<endl;
    int nodes;
    cin>>nodes;

    cout<<"Enter the number of edges"<<endl;
    int edges;
    cin>>edges;

    graph<int> g;
    cout<<"Enter edges"<<endl;
    for(int i = 0; i< edges ; i++){
        int u , v;
        cin>> u >> v;
        g.addEdge(u , v ,0);  //0 means undirected graph
    }

    g.printAdjList();
}