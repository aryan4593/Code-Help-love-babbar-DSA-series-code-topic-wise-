#include<iostream>
using namespace std;

int fact ( int a){
    int fact = 1;
    for (int i =1; i<=a; i++){
        fact = fact *i;
    }
    return fact;
}
int ncr (int z, int b){
    int NCR;
    NCR = fact(z)/(fact(z-b)*fact(b));

    return NCR;
}

int main (){

    cout<<fact(5)<<endl;

    cout<<ncr(3,2)<<endl;
}