#include<iostream>
using namespace std;

int getLegth (char arr[])
{
    int count =0; int i =0;
    while(arr[i]!='\0'){
        count++;
        i++;
    }

    return count;
}
int main (){
    char name[20];
    cout<<"Enter your name ";
    cin>>name;

    cout<<"length of string is " << getLegth(name);


    //Imp - cin will stop execution after space,TAB,ENTER
}