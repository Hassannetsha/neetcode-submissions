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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        ListNode*head = nullptr,*tem;
        bool allNull = false;
        while(!allNull){
            allNull  = true;
            int idx = -1,mn = 1001;
            for(int i = 0;i<lists.size();i++){
                if(lists[i]&&mn>lists[i]->val){
                    idx = i;
                    mn = lists[i]->val;
                }
                if(lists[i]){
                    allNull = false;
                }
            }
            if(!head){
                head = new ListNode(mn);
                tem = head;
            }
            else if (!allNull){
                tem->next = new ListNode(mn);
                tem = tem->next;
            }
            else{
                break;
            }
            ListNode* temp = lists[idx];
            lists[idx] = lists[idx]->next;
            delete temp;
        }
        return head;
    }
};
