#include<iostream>
#include<map>
using namespace std;

int main (){
    map<int,string> m;
    m[1]="aryan";       // 3 is key here
    m[2]= "Dnayaneshwar";
    m[3]= "Pungale";
    m.insert({5,"VIT"});

    for (auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"finding 13"<<m.count(13)<<endl;

    m.erase(5);

    auto it = m.find(5);

    for (auto i = it;i!=m.end();i++){
        cout<<(*i).first<<endl;
    }
}