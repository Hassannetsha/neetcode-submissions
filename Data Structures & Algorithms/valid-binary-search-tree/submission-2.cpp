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
    bool dfs(TreeNode* root,int left,int right){
        if(!root)
            return true;
        if(!(root->val<right&&root->val>left))
            return false;
        return dfs(root->right,root->val,right)&&dfs(root->left,left,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,-1001,1001);
    }
};
