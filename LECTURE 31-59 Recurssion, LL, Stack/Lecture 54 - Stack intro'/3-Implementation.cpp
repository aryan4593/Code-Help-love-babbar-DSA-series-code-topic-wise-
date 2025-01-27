#include<iostream>
using namespace std;
const int size = 50;
class Stack{
    public:
    int top;
    int* arr ;
    int size;


//stack
    Stack(int size){
        this->size = size;
        this->arr= new int[size];
        top=-1;
    }

    void push(int data){
        if (top<size){
            top++;
            arr[top]=data;
            cout<<"top data is "<<arr[top]<<endl;
        }

        else cout<<"stack overflow"<<endl;
    }

    void pop (){
        if(top>=0){
            top--;
        }
        else cout<<"stack underflow;"<<endl;
    }
    bool isEmpty(){
        if (top==-1){
            return true;
        }
        return false;
    }
    
    int peek(){
        if(top>=0 and top<size){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }

    }
};

int main(){
    Stack st(5);
    st.push(22);
    st.push(44);
    st.push(66);

    cout<<"peak element is "<<st.peek()<<endl;
    st.pop();
    cout<<"peak element is "<<st.peek()<<endl;
    st.pop();

    st.pop();
    cout<<"peak element is "<<st.peek()<<endl;

    


}