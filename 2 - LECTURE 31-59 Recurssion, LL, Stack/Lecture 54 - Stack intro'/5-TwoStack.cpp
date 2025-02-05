//we will fill stack one R ot left and stack 2 left to right
#include<iostream>
using namespace std;


class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

public:
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = size;
        arr = new int[s];
    }

    void push1(int num) {
        if (top1 < top2 - 1) {
            arr[++top1] = num;
        } else {
            cout << "Stack1 Overflow" << endl;
        }
    }

    void push2(int num) {
        if (top1 < top2 - 1) {
            arr[--top2] = num;
        } else {
            cout << "Stack2 Overflow" << endl;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack1 Underflow" << endl;
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack2 Underflow" << endl;
            return -1;
        }
    }

    ~TwoStack() {
        delete[] arr;
    }
};