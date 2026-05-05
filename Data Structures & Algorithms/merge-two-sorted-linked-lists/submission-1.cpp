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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = nullptr,*ptr = nullptr;
        while(list1!=nullptr&&list2!=nullptr){
            ListNode* temp = nullptr;
            if(list1->val<list2->val){
                temp = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                temp = new ListNode(list2->val);
                list2 = list2->next;
            }
            if(ans ==nullptr){
                ans = temp;
                ptr = ans;
            }
            else{
                ptr->next = temp;
                ptr = temp;
            }
        }
        while(list1!=nullptr){
            ListNode* temp = new ListNode(list1->val);
            list1 = list1->next;
            if(ans ==nullptr){
                ans = temp;
                ptr = ans;
            }
            else{
                ptr->next = temp;
                ptr = temp;
            }
        }
        while(list2!=nullptr){
            ListNode* temp = new ListNode(list2->val);
            list2 = list2->next;
            if(ans ==nullptr){
                ans = temp;
                ptr = ans;
            }
            else{
                ptr->next = temp;
                ptr = temp;
            }
        }
        return ans;
    }
};
