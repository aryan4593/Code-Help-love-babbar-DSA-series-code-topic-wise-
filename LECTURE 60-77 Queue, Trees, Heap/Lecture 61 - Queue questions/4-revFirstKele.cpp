#include<iostream>
#include<stack> 
#include<queue>
using namespace std;
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int>s;
        for(int i =0;i<k;i++){
            s.push(q.front());
            q.pop();
        }
        for(int i =0;i<k;i++){
            q.push(s.top());
            s.pop();
        }
        for(int i =0;i<q.size()-k;i++){
            int ele =q.front();
            q.pop();
            q.push(ele);
        }
        return q;
    }
};
