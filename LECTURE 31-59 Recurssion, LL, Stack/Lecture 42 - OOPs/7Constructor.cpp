#include<iostream>
using namespace std;
class hero {
    private:
    int health;

    public:
    char level;
    int getHealth(){
        return health;      
    }
    void setHealth (int h){
        health =h;              
    }

    hero(){
        //when we right our own constructor, default constructor made by system is gone
        cout<<"constructer is called \n";
        cout<<"this-->"<<this<<endl;
    }

    //parametrised constructer
    hero (int health,char level){
        (*this).level = level;        // in 'this' keyword the address of current object is stored, means here address of ramesh will be stored 
        this->health = health;    //or    
    }
};
int main (){
 hero ramesh;

 cout<<"address of ramesh is "<<&ramesh<<endl;

//dynamically
hero *h = new hero(88,'a');

 /*
when we create object, constructor is called;
constructor -object creation k time invoke hota hai 
            no return type
            no input parameter
*/

//there is always a default constructor means ramesh.hero();

}


