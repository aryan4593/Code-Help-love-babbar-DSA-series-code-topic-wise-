#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* findMid (ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast= fast->next->next;
            slow = slow ->next;
        }

        return slow;
    }

    ListNode* merge (ListNode* first, ListNode* second){
        // use merge 2 sorted linked list algo
        ListNode* curr1 = first;
        ListNode* next = first->next;
        ListNode* curr2 = second;

        if(next==NULL){
            curr1->next = curr2;
        }
        while (next!=NULL && curr2!=NULL){
        if (curr2->val >= curr1->val && curr2->val<= next->val){
            ListNode* temp = curr2;
            curr2=curr2->next;
            curr1->next = temp;
            temp->next = next;
            curr1 = curr1->next;
        }

        else{
            curr1=curr1->next;
            next = next->next;
        }

        }

        if (curr2!=NULL){
            curr1->next =curr2;
        } 

return first;

        

    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next ==NULL){
            return head;
        }

        ListNode* mid = findMid(head);
        ListNode* l2= mid->next;
        mid->next =NULL;
        ListNode* l1 = head;
        l1= sortList(l1);
        l2 = sortList(l2);
        ListNode* ans=NULL;

        if (l2->val < l1->val )
          ans = merge (l2,l1);

        else ans = merge(l1,l2);
return ans;
    }
};


// T = n(log (n))
// s = log n