
#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect if there is a cycle
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;  // Move fast by two steps
            slow = slow->next;        // Move slow by one step

            if (fast == slow) { // Cycle detected
                break;
            }
        }

        // If no cycle was detected, return NULL
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Phase 2: Find the start of the cycle
        slow = head; // Move slow to the start of the list

        while (slow != fast) { // Move both one step at a time
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // The start of the cycle
    }

    void removeLop (ListNode* head){
        if (head == NULL){
            return;
        }
        ListNode* startOfLoop = detectCycle(head);
        ListNode* temp = startOfLoop;
        while (temp->next!=startOfLoop){
            temp = temp->next;
        }

        temp->next = NULL;
    }
};
