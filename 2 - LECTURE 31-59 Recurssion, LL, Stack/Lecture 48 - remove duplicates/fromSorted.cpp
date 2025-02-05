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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        if (head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* frwd=NULL;

        while (temp!= NULL){
            frwd = temp->next;
            if (frwd  ==NULL){
                break;
            }

        if (temp->val == frwd->val){
            temp->next = frwd->next;
            frwd->next = NULL;
            delete frwd;
        }
        else
        temp=temp->next;

    }
        return head;}
};
//t = n
//s =cons