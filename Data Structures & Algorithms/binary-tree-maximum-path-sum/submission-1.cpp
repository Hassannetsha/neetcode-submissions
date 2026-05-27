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
    // int mxSum;
    // int mxSum;
    int dfs(TreeNode* root,int& sum){
        if(!root){
            // mxSum = max(mxSum,sum);
            return 0;
        }
        int leftSum = max(dfs(root->left,sum),0);
        int rightSum = max(dfs(root->right,sum),0);
        // if(root->val<0){
        //     // mxSum = max(mxSum,sum);
        // }
        // if(root->val>=0){
            sum=max(sum,root->val + leftSum + rightSum);
            // if(root->left&&root->left->val>=0)
                // sum+=max(leftSum,0);
            // if(root->right&&root->right->val>=0)
                // sum+=max(rightSum,0);
            // else
            // sum = max(sum,leftSum);
            // else
            // sum = max(sum,rightSum);
        // }
        // else{
        //     sum = max(sum,max(leftSum,rightSum));
        // }
        // mxSum = max(max(mxSum,sum),max(leftSum,rightSum));
        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        // mxSum = 0;
        int sum = root->val;
        dfs(root,sum);
        return sum;
    }
};
