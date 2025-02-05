// using recursion
#include<bits/stdc++.h>
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
    void reverse(ListNode*& head, ListNode* curr, ListNode* prev) {
        if (curr== NULL){
            head = prev;
            return;
        }

        
        ListNode* frwd = curr->next;
        prev = curr;
        reverse (head,frwd,prev);
        curr->next = prev;
}};