#include<iostream>
using namespace std;
#include<string>
  struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
int getLength(ListNode* head){
    int count =0;
    while (head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
    bool isCircular (ListNode* head){
        if (head==NULL){
            return true;
        }
        // if (head->next==head){
        //     return true;
        // }
        // if (head->next==NULL){
        //     return false;
        // }  logic coved below

        ListNode* temp =head->next;
        while (temp!=NULL && temp!=head){
            temp=temp->next;
        }
        if (temp == head){
            return true;
        }
        else return false;
    }

    
};




// time complexity= O(n)
// space complexity = O(1)


//approach 2 uses map