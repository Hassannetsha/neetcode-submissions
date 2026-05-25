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
    // vector<int>vec;
    int val;
    int dfs(TreeNode* root,int&cnt,int k){
        if(!root){
            val ==-1? -1:val;
            return val;}
        dfs(root->left,cnt,k);
        cnt++;
        if(cnt==k){
            val = root->val;
            return val;}
        // vec.push_back(root->val);
        dfs(root->right,cnt,k);
        return val;

    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        val = -1;
        return dfs(root,cnt,k);
        
    }
};
