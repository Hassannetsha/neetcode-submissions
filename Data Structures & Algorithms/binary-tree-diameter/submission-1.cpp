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
    pair<int,int> depth(TreeNode* root){
        if(!root)
            return make_pair(0,0);
        pair<int,int> rightmx = depth(root->right);
        pair<int,int> leftmx = depth(root->left);
        int mxans = max(max(rightmx.first,leftmx.first),rightmx.second+leftmx.second);
        int mxdepth = max(rightmx.second,leftmx.second);
        pair<int,int>ans = {mxans,mxdepth+1};
        return ans;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        return depth(root).first;
    }
};
