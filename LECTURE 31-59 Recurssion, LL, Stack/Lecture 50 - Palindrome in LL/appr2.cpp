//get middle
// reverse linked list after middle
// compare both parts

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
    ListNode* getMid (ListNode* head){
        ListNode* slow=head;
        ListNode* fast = head->next;

        while (fast!=NULL && fast->next!=NULL){
            fast= fast->next->next;
            slow=slow->next;
        }

        return slow;
    }
    ListNode* reverse(ListNode* &head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next=NULL;

        while (curr!=NULL){
            next=curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        bool ans = true;
        ListNode* mid = getMid(head);
        ListNode* temp = mid ->next;
        mid->next = reverse(temp);
        ListNode* head1= head;
        ListNode* head2 = mid->next;
        while (head2!=NULL && head1!= mid->next){
            if (head1->val != head2->val){
                ans = false;
            }
            head1=head1->next;
            head2=head2->next;
        }
return ans;
    }
};
int main ()


{

}