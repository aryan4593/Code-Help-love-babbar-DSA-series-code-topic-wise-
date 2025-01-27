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
    hero ramesh;
    ramesh.setHealth(700);
    cout<<"health of ramesh is "<<ramesh.getHealth()<<endl;
    cout<<"size of ramesh is "<<sizeof(ramesh)<<endl;  //size came more because of padding
    return 0;
}