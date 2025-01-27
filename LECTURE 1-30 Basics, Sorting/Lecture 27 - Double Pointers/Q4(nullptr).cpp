#include<iostream>
using namespace std;

int main (){
   int *p =0;
   int first =110;
   *p = first; //segmentation fault
   cout<<*p<<endl;

    return 0;
}