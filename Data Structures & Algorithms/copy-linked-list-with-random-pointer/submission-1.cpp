/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead  = nullptr,*temp, *temphead = head;
        unordered_map<Node*,Node*>mp;
        while(temphead){
            if(!newHead){
                newHead = new Node(temphead->val);
                temp = newHead;
            }
            else{
                temp->next = new Node(temphead->val);
                temp = temp->next;
            }
            mp[temphead] = temp;
            temphead = temphead->next;
        }
        temp = newHead;
        temphead = head;
        while(temphead){
            if(temphead->random)
            {
                temp->random = mp[temphead->random];
            }
            temphead = temphead->next;
            temp = temp->next;
        }
        return newHead;
    }
};
