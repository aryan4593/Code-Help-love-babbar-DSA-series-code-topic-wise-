#include<iostream>
using namespace std;

int main (){
    cout<<"enter your no. "<<endl;
    int n; cin>>n;
    int i=1,j=1;int k=1;
    for (i = 1; i<=n;i++){
        int j=1;
        while (j<=n){
            
            cout<<k<<" ";
            j++;
            k++;
        }
        cout<<endl;

    }
}