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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr ,*temp = nullptr;
        int sum = 0;
        while(l1&&l2){
            if(!head){
                sum += l1->val + l2->val;
                head = new ListNode(sum%10);
                temp = head;
                sum/=10;
                // if(sum){
                //     temp->next = new ListNode(sum);
                //     temp = temp->next;
                // }
            }
            else{
                sum += l1->val + l2->val;
                temp->next = new ListNode(sum%10);
                sum/=10;
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            if(sum){
                sum+=l1->val;
                temp->next = new ListNode(sum%10);
                sum/=10;
            }
            else{
                temp->next = new ListNode(l1->val);
            }
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2){
            if(sum){
                sum+=l2->val;
                temp->next = new ListNode(sum%10);
                sum/=10;
            }
            else{
                temp->next = new ListNode(l2->val);
            }
            temp = temp->next;
            l2 = l2->next;
        }
        if(sum)
        {
            temp->next = new ListNode(sum);
        }
        return head;
    }
};













