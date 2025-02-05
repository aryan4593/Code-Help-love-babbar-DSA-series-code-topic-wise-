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
    bool check (vector<int> arr){
        int s =0, e = arr.size()-1;
        bool ans = true;
        while (s<=e){
            if (arr[s]!=arr[e]){
                ans = false;
            }
            s++, e--;
        }
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        while (temp!=NULL){
            arr.push_back (temp->val);
            temp = temp-> next;
        }
return check (arr);

    }
};