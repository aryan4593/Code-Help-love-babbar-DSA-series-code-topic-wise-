#include<iostream>
using namespace std;

int main (){
int n; cin>>n;
 char ch = 'A';
for (int i = 1; i<=n;i++){
    for (int j = 1; j<=n;j++){
       ch = 'A'+i-1+j-1;
        cout<<ch;
        
}

cout<<endl;
}

}