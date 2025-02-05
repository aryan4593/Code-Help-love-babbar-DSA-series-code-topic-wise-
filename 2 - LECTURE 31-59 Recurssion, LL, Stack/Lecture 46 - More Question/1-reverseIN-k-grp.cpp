#include<iostream>
using namespace std;
#include<string>
  struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
int getLength(ListNode* head){
    int count =0;
    while (head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head ==NULL){
            return head;
        }
        
        //step1 reverse first k nodes
        ListNode*next =NULL;
        ListNode* curr= head;
        ListNode* prev =NULL;
        int count =0;
        if (getLength(head)<k){
            return head;
        }
        while (curr!=NULL && count<k){
            next =curr->next;
            curr->next = prev;
            prev = curr;
            curr=next; 
            count++;
        }
        //step 2 recussion
        if (next!=NULL){
            head->next = reverseKGroup(next,k);
        }

        return prev;

    }
};



// time complexity=space complexity = O(n)