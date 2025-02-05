#include <iostream>
using namespace std;
#include <stack>
class NStack
{
    int *arr;
    int *next; // next array
    int *top;  // top array
    int n, s;
    int freeSpot;

public:
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top =new int [n];
        next = new int [s];
        // top intialize
        for (int i = 0; i < s; i++)
        {
        top[i]= -1;
            /* code */
        }
        

        //next initialize
        for (int i = 0; i < s; i++)
        {
            next[i]=i+1;
        }
        //update last index to -1
        next[s-1]= -1;
        freeSpot=0;
        }

    bool push(int x, int m)
    {
        //check stackoverflow
        if(freeSpot==-1){
            return false;
        }

        //find index
        int index = freeSpot;
        freeSpot=next[index];

        //insert element in array
        arr[index]=x;

        //update next;
        next[index]= top[m-1];

        // update top 
        top[m-1]=index;
        return true;
    }

    int pop(int m)
    {
        //underflow
        if(top[m-1]==-1){
            return -1;
        }

        int index = top[m-1];
        top[m-1]=index;
        next[index]=freeSpot;
        freeSpot=index;
        return arr[index];

    }
};
int main()
{
    NStack st(4, 4);
}