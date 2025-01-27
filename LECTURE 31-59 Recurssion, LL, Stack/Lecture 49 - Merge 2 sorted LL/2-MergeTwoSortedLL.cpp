 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

    void solve (ListNode* &first,ListNode* &second){
        ListNode* curr1 = first;
        ListNode* next1 = curr1->next;
        ListNode* curr2=second;

        if (first->next == NULL){
            first->next = second;
            return;
        }

        while (next1!=NULL && curr2 !=NULL){
            if ((curr2->val<= next1->val) && (curr2->val>=curr1->val)){
                ListNode* temp = curr2;
                curr1->next = temp;
                curr2=curr2->next;
                temp->next = next1;
                curr1= curr1->next;
            }
            else {
                curr1=next1;
                next1 = next1->next; 
            }

        }
        if (curr2!=NULL){
            curr1->next = curr2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL){
            return list2;
        }
        if (list2==NULL){
            return list1;
        }

        if (list1->val<=list2->val){
            solve (list1,list2);
            return list1;
        }
        else 
            solve (list2,list1);
            return list2;
        
    }
};