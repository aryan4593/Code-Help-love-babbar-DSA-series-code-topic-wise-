//floys's cycle detection algorithm - fast, slow

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
    bool hasCycle(ListNode *head) {
        if (head == NULL){
            return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;

        while (slow!=NULL && fast!=NULL){
            fast = fast->next;

            if(fast!=NULL)
            fast = fast->next;

            slow = slow->next;

            if (slow == fast){
                return 1;
            }
        }
        return false;

        /*for starting point of node-
        
        //after finding first intersection set slow as head again
        slow = head;
        while ( fast!=NULL){
            fast = fast->next; // increase speed same as slow

            slow = slow->next;

            if (slow == fast){
                return slow; //this is the position of starting point 
            }
        }
        */

    }
};


//time comop = O(n)
//space = O(1)