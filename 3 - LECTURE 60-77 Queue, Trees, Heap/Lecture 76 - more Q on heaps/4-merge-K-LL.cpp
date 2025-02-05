#include<iostream>
#include<queue>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 


class compare{
    public:
    bool operator()(ListNode* a, ListNode*b){
        return a->val > b->val;
    }
};
class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare> minHeap;
        if(lists.size()==0) return nullptr;
        for(int i = 0; i < lists.size() ; i++){
            if(lists[i] != NULL)
            minHeap.push(lists[i]);
        }
        ListNode* head= NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
        ListNode* temp = minHeap.top();

        minHeap.pop();
        if(!head){
            head = temp;
            tail = temp;

        if(tail->next){
                minHeap.push(tail->next);
        }
        }
        tail -> next = temp;
        tail = temp;
        if(tail->next){
            minHeap.push(tail->next);
        }

        return head;
    }
}};