#include<iostream>
using namespace std;
#include<map>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL){
            return false;
        }
        if (head->next == head){
            return true;
        }
        if (head->next == NULL){
            return false;
        }
        map<ListNode*, bool>visited;

        ListNode*temp = head;
        while (temp!=NULL){
            if (visited[temp]==true){
                break;
            }
            visited[temp]= true;
            temp = temp->next;

        }

        if (temp == NULL){
            return false;
        }
        else return true;
    }
};