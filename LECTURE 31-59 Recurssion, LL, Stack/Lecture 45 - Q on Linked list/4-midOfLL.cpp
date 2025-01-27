/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int lengthOfLL(ListNode*head){
        int cnt =0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
    ListNode* middleNode(ListNode* head) {
        int mid = (lengthOfLL(head)/2)+1;
        ListNode*  curr=head;
        for(int i =1;i<mid;i++){
            curr=curr->next;
        }
        return curr;
    }
};

comp =  o(n);