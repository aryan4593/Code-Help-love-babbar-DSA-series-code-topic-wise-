#include<iostream>
#include <queue>
using namespace std;

int main (){
   // max heap
   priority_queue <int> maxi;

   //min heap
   priority_queue<int,vector<int>,greater<int> > mini;
   maxi.push(1);
   maxi.push(3);
   maxi.push(2);
   maxi.push(0);
    cout<<" size is "<<maxi.size()<<endl;
    int n = maxi.size();
   for (int i =0; i< n;i++){
    cout<<maxi.top()<<" ";
    maxi.pop();
   }


    mini.push(3);
   mini.push(4);
   mini.push(5);
   mini.push(1);
cout<<endl<<endl;
    int m = mini.size();
   for ( int j =0; j< m;j++){
    cout<<mini.top()<<" ";
    mini.pop();
   }


}