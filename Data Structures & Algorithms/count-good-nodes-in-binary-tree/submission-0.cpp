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
    int maxDfs(TreeNode* root,int mx){
        if(!root)
            return 0;
        // int add = 0;
        // if(){
        //     add+=1;
        // }
        int left = maxDfs(root->left,max(mx,root->val));
        int right = maxDfs(root->right,max(mx,root->val));
        return left + right + (root->val>=mx);
    }
    int goodNodes(TreeNode* root) {
        return maxDfs(root,-101);
        
    }
};
