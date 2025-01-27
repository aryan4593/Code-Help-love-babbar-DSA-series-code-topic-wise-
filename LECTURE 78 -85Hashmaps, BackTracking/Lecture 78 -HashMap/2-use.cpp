#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;

    //insertion
    pair<string,int> p = make_pair("aryan" , 2);
    m.insert(p);

    pair<string,int> p2 ("aryan" , 2); 
    m.insert(p2);

    m["Rohit"] = 45;

    //search
    cout<<m["aryan"]<<endl; 
    cout<<m.at("Rohit")<<endl; 
    cout<<m["unknownn"]<<endl; //as unknownn key won't exist it will make a entry of 0 corr to string
    // cout<<m.at("unknown")<<endl; //but this won't make a entry it will throw a exception

    //size
    cout<<"size : "<<m.size()<<endl;

    //check existence
    cout<<m.count("Hitman")<<endl; //this wont create any pair it just gives 0 or 1

    m.erase("aryan");

//access
    for(auto i:m){
        cout<<i.first <<" "<<i.second<<endl;
    }
    //iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first <<" "<<it->second<<endl;
        it++;
    }
        //in unordered map, things are stored in random order
        //to avoid this use normal map


return 0;
}