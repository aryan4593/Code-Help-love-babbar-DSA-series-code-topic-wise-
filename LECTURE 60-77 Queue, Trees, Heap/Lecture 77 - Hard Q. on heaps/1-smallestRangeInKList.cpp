#include<iostream>
#include<limits>
#include<queue>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    int row;
    int col;

    node( int d , int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT32_MAX;
        int maxi = INT32_MIN;
        vector<int> results;
        priority_queue<node*, vector<node*>, compare> minHeap;

        for(int i = 0; i< nums.size(); i++){
            int element = nums[i][0];
            maxi = max(maxi , element);
            minHeap.push(new node(element , i , 0));
        }

        int start = minHeap.top()->data, end = maxi;
                results.push_back(start);
                results.push_back(end);
        while(!minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();

            mini = temp->data;

            if(maxi -  mini < end - start){
                start = mini ;
                end = maxi;

                while(!results.empty()){
                    results.pop_back();
                }
                results.push_back(start);
                results.push_back(end);

            }
            int index = temp -> col;
            if(index + 1 < nums[temp->row].size()){
                maxi = max(maxi,nums[temp->row] [temp -> col+1]);
                minHeap.push(new node(nums[temp->row] [temp->col +1], temp->row , temp->col + 1));
            }
            else break;

        }

        return results;
    }
};