#include<iostream>
using namespace std;


void printCounting (int n){
    cout<<n<<" ";
    if (n==1){
        return;
    }

    printCounting(n-1);
}
int main (){
    int n;
    cin>>n;
    printCounting(n);
    return 0;
}