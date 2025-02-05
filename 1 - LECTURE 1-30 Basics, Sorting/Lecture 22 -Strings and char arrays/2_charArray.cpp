#include<iostream>
using namespace std;

int main (){
    char name[20];
    cout<<"Enter your name ";
    cin>>name;

    cout<<endl<<"your name is "<<name<<endl;

    
    name[2]='\0';  
    cout<<"Name 2 is "<<name;


    //Imp - cin will stop execution after space,TAB,ENTER
}