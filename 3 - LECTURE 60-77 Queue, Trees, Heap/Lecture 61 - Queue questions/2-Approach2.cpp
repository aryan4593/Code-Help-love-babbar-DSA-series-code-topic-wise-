#include<iostream>
#include<stack> 
#include<queue>
using namespace std;
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
    if(q.empty()){
        return q;
        cout<<"returned queue"<<endl;
    }
        int ele=q.front();
        cout<<"poped "<<ele<<endl;
        q.pop();

        q=rev(q);
        cout<<"pushed "<<ele<<endl;
        q.push(ele);
        return q;
    }
};

int main (){
    Solution s1;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    q=s1.rev(q);
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    
    return 0;
}