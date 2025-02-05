#include<iostream>
using namespace std;

int main (){
    char ch='q';
    cout<<"size of ch is "<<sizeof(ch)<<endl;

    char*c = &ch;
    cout<<"size of c is "<<sizeof(c)<<endl;
    return 0;
}