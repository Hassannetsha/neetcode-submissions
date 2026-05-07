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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head,*prev;
        int sz = 0;
        while(temp){
            sz++;
            temp = temp->next;
        }
        if(n==1&&sz==1){
            return nullptr;
        }
        int idx = 0,target = sz - n;
        prev=head;
        temp = head;
        while(idx<target){
            prev = temp;
            temp = temp->next;
            idx++;
        }
        if(temp==head){
            // head = head->next;
            return temp->next;
        }
        prev->next = temp->next;
        return head;
    }
};
