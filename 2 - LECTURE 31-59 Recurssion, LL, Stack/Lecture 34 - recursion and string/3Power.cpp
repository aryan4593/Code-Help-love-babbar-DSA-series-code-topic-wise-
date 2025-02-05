#include<iostream>
using namespace std;

int power (int a , int b){
    if (b==0){
        return 1;
    }
    if (b==1)
        return a;

    if (b%2==1){
        return 2* power(a,b/2)*power(a,b/2);
    }
   else {power(a,b/2)*power(a,b/2);
    }

}
int main (){
    cout<<"a^b";
    cout<<"enter a and b ";
    int a,b; cin>>a>>b;

    cout<<a<<"^"<<b<<" is "<<power(a,b);
    return 0;
}