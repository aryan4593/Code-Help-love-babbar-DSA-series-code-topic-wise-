#include<iostream>
using namespace std;

int fastPower(int x,int n){
int res =1;
    while(n>0){
        
        if (n%2==1){
            res = res*x;
        }
        x=x*x;
        n=n/2;
    }
    return res;
}

int main (){
    int x=2,n=5;
    cout<<fastPower(2,5);
    return 0;
}