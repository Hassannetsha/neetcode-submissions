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
    ListNode* temp;
    ListNode* temp2;
    bool done = false;
    void f(ListNode* temp2){
        if(temp2==nullptr){
            return;
        }
        f(temp2->next);
        if(done){
            return;
        }
        if(temp == temp2||temp->next==temp2){
            temp2->next = nullptr;
            done = true;
            return;
        }
        ListNode* temp3 = temp->next;
        temp->next = temp2;
        temp2->next = temp3;
        temp = temp3;
    }
    void reorderList(ListNode* head) {
        temp = head;
        temp2 = head;
        f(head->next);
        head = temp2;
    }
};
