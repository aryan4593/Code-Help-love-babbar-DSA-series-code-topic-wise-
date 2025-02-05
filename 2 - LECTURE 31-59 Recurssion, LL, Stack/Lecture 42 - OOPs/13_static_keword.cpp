#include<iostream>
#include<string.h>
using namespace std;

class hero {
    private:
        int health;

    public:
        char level;
        char *name;
        static int timeToComplete;  //time to complete is independant thing i.e it is same for enemy and hero so why do we need to create object for this??

        static int staticFunc (){
            //static function can only access static members
            //static function don't have any this keyword
            cout<<"time to comoplete is " <<timeToComplete-<<endl;
        }

};

int hero::timeToComplete=5;
int main() {
    cout<<hero::timeToComplete<<endl;
    hero a;
    cout<<a.timeToComplete;  //not recommended as [1]
    
}

//[1] static members don't belong to objects it belongs to class!
//static function too don't need to crea
