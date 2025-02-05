#include<iostream>
#include<stack> 
#include<queue>
using namespace std;
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }

        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        return q;
    }
};

int main (){

    return 0;
}