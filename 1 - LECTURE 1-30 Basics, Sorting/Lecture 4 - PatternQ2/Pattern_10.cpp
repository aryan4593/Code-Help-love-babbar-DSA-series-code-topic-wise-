#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter size of square"<<endl;
    int n; cin>>n;

    for(int i = 0 ; i < n ; i++){

            if(i == 0 or i == n-1){
                for(int k = 0 ; k < n ;k++) cout<<"* ";
                cout<<endl;
                continue;
            }
        for(int j = 0; j < n ; j++){
            if(j == 0 || j == n - 1) cout<<"* ";
            else cout<<"  ";
        }
        cout<<endl;
    }
}