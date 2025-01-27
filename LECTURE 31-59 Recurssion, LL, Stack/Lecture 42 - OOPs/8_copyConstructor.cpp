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
        cout<<"constructer is called \n";
    }


    hero (int health,char level){
        (*this).level = level;        
        this->health = health;       
    }
    void print (){
        cout<<"helath is "<<health<<endl;
        cout<<"level is "<<level<<endl;
    }

    hero (hero &temp){ //user made copy constructer
        this->health = temp.health;
        this->level = temp.level;
    }
};
int main (){
    hero S(70,'c');
    hero R (S);     // this is copy constructor which is there by default
    // this means R.health = S.health and R.level = S.level
    R.print();
    S.print();

}


