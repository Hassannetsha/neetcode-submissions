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
    int depth(TreeNode* root,int&mxans){
        if(!root)
            return 0;
        int rightmx = depth(root->right,mxans);
        int leftmx = depth(root->left,mxans);
        mxans = max(mxans,rightmx+leftmx);
        int mxdepth = max(rightmx,leftmx);
        int ans= mxdepth+1;
        return ans;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        depth(root,res);
        return res;
    }
};
