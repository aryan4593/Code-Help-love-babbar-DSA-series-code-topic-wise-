#include<iostream>
using namespace std;

int main (){

    //case 1
    while(true){
        int *ptr=new int;
        int *arr = new int[50];
        cout<<"..";
        //*ptr will get free but new int will remain as it it is 
        // heap memory don't get free automaticallu like in static allocation(in CPP)
        delete ptr;  //this is how you delete memory
        delete []arr; //this is how you delete array
    }
    return 0;
}