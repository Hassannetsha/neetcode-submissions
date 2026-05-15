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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        stack<pair<TreeNode*,int>>st;
        st.emplace(root,1);
        int depth = 0,mx_depth = 0;
        while(!st.empty()){
            TreeNode* node = st.top().first;
            depth = st.top().second;
            st.pop();
            if(node->right) st.emplace(node->right,depth+1);
            if(node->left) st.emplace(node->left,depth+1);
            mx_depth = max(mx_depth,depth);
        }
        return mx_depth;
    }
};
