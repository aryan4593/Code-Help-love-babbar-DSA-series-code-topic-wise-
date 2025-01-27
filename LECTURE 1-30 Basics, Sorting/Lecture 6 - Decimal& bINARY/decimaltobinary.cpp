#include<iostream>
#include<math.h>
using namespace std;

int main (){

    cout<<"Enter n: ";
    int n; cin>>n;
    int bit; int ans=0;
    int i =0;
    while (n!=0){
        bit = n&1;
        ans = bit*pow(10,i) + ans;
        i++;
        n = n>>1;
    }
    cout<<ans;

}