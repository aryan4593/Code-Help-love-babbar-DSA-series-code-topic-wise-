#include<iostream>
using namespace std;
#include<string>

void reverse (string &str,int s, int e){
    cout<<s<<" "<<e<<endl;
    if (s>=e){
        cout<<"reached if "<<endl;
        return ;
    }
    swap (str[s],str[e]);
    s++;e--;
    reverse (str,s,e);
}
int main (){
    string s  ="adasf";
    reverse (s,0,s.length()-1);
    cout<<s;
    return 0;
}