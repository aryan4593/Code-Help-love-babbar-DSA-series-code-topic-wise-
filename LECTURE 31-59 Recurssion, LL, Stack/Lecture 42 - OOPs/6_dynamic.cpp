#include<iostream>
using namespace std;
class hero {
    private:
    int health;

    public:
    char level;
    int getHealth(){
        return health;      //this is getter which returns us health
    }
    void setHealth (int h){
        health =h;              //this is setter which sets health
    }
};
int main (){
    //statically
    hero ramesh;
    ramesh.setHealth(70);
    ramesh.level='a';
    cout<<"level is "<<ramesh.level;
    cout<<"level is "<<ramesh.getHealth();

    //dynamically -
    hero *b = new hero;
    b->level =79;
    //or
    (*b).level =78;
    cout<<"level is "<<(*b).level;              // use de reference operator
    cout<<"level is "<<(*b).getHealth();

    //alterenative way
    b->setHealth(5); 
    b->getHealth();
    
}