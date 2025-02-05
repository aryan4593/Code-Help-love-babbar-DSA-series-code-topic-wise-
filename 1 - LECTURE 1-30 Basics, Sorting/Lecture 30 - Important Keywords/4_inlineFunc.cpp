#include<iostream>
using namespace std;

void func (int a, int b){
    a++;
    b++;
    cout<<a<<" "<<b<<endl;
}

inline int getmax(int &a,int b){        //this is inline function
//before compilation, inline function getmax will be replaced by this line
//inline function can be only of max 2-3 lines
   return (a>b) ? a:b;
}
int main(){
int a=21,b=54;
func(a,b);
int ans;
/*
if (a>b){
    ans =a;
}
else ans =b;
*/

//we can write this using tertiary operator
// ans = (cond) ? true:false
ans = getmax(a,b);
 
a++; b+=3;
ans=getmax(a,b);



}