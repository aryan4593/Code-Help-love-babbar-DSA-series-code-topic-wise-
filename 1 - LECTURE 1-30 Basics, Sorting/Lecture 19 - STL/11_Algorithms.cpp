#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main (){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    cout<<"finding 5 --> "<<binary_search(v.begin(),v.end(),5);
  
    cout<<"\nlower bound " <<lower_bound(v.begin(),v.end(),5) - v.begin()<<endl;
    cout<<"upper bound " <<upper_bound(v.begin(),v.end(),5) - v.begin()<<endl;

    int a =3,b=5;
    max(a,b); min (a,b); swap (a,b);

    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<abcd<<endl;

    rotate(v.begin(),v.begin()+1,v.end());
    for (int i:v){
        cout<<i<<" ";
    }

    sort(v.begin(),v.end());  // intro sort
}