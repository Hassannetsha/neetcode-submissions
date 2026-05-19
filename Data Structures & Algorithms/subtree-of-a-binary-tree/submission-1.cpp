/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)
            return true;
        else if(p&&!q||!p&&q)
            return false;
        else if(p->val!=q->val)
            return false;
        bool right = isSameTree(p->right,q->right);
        bool left = isSameTree(p->left,q->left);
        return right&left;
    }
    bool isSubroot = false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return isSubroot;
        }
        if(root->val==subRoot->val){
            isSubroot = isSameTree(root, subRoot);
            if(isSubroot)
                return isSubroot;
        }
        bool right = isSubtree(root->right,subRoot);
        bool left = isSubtree(root->left,subRoot);
        return (right||left);
    }
};













