#include<iostream>
using namespace std;

int main (){
    int first =8;
    int second = 18;
    int *ptr = &second;
    *ptr=9;     //means it will change second
    cout<<first<<" "<<second<<endl;

    return 0;
}