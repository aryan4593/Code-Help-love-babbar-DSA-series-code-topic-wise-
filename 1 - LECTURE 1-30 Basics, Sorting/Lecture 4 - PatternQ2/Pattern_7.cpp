#include<iostream>
using namespace std;

int main (){
int i;int j;
int n; cin>>n;

for (i=1;i<=n;i++){
    int z = i;
    for(j=1;j<=i;j++){
        cout<<z;
        z--;
    }
    cout<<endl;
}

}