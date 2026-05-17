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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        unordered_map<TreeNode*,int>mp;
        stack<TreeNode*>st,nodes;
        mp[nullptr] = 0;
        st.push(root);
        nodes.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            mp[node] = 0;
            if (node->right){
                st.push(node->right);
                nodes.push(node->right);
            }
            if(node->left)
            {
                st.push(node->left);
                nodes.push(node->left);
            }
        }
        while(!nodes.empty()){
            TreeNode* node = nodes.top();
            nodes.pop();
            if(abs(mp[node->right]-mp[node->left])>1){
                return false;
            }
            else{
                mp[node] = max(mp[node->right],mp[node->left])+1;
            }
        }
        return true;
    }
};
