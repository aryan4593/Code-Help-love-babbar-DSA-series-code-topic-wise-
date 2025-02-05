#include<iostream>
using namespace std;
class A {
    public:
       void sayhello(){
        cout<<"hello Aryan"<<endl;
       }
       void sayhello(char a){               //function overloading by using differenr parameters
        cout<<"hello Aryan"<<endl;            
       }
};

int main(){
A obj;
obj.sayhello();
}