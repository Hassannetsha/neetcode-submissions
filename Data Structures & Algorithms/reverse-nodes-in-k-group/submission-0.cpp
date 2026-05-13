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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!(head->next)||k==1){
            return head;
        }
        vector<ListNode*>vec;
        while(head){
            vec.push_back(head);
            head = head->next;
        }
        int l = 0,r = k-1;
        while(r<vec.size()){
            int templ = l,tempr = r;
            while(templ<tempr){
                swap(vec[templ]->val,vec[tempr]->val);
                templ++;
                tempr--;
            }
            l+=k,r+=k;
        }
        return vec[0];
    }
};
