#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



    ListNode* reverseList(ListNode* head) {
        if (head ==NULL || head->next == NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* frwd =NULL;
 
        while (curr!=NULL){
            frwd = curr->next;
            curr->next =prev;
            prev = curr;
            curr=frwd;
        }
        return prev;
    }


    int main() {
        // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        // Reverse the linked list
        head = reverseList(head);

        // Print the reversed linked list
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }



        return 0;
    }