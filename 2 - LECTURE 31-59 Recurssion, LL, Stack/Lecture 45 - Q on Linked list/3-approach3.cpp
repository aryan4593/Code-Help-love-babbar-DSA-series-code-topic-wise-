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
    ListNode* reverse1(ListNode* head){
        if (head== NULL || head->next ==NULL){
            return head;
        }
        ListNode* smallListHead = reverse1(head->next) ; //for small list;
        head->next->next = head;
        head->next =NULL;
        return smallListHead;
    }
    ListNode* reverseList(ListNode* head) {
       return reverse1(head); 
    }
};

// Tc = O(n)