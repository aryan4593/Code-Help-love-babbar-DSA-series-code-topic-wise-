#include<iostream>
#include<queue>

using namespace std;
class Solution {
public:
queue<int> q;
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit=0;
        int balance =0;
        int start=0;

        for(int rear =0;rear<gas.size();rear++){
            balance+=gas[rear]-cost[rear];
            if(balance<0){
                start=rear+1;
                deficit+=balance;
                balance=0;
            }

        }
        if(deficit+balance>=0){
            return start;
        }
        else return -1;
        }
    
};
int main(){

}