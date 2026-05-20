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
    void dfs(TreeNode* root,deque<TreeNode*>&dequ,bool& found,TreeNode* p){
        if(found){
            dequ.pop_back();
            return;
        }
        else if(!root){
            dequ.pop_back();
            return;
        }
        else if(p->val == root->val){
            found = true;
            return;
        }
        dequ.push_back(root->right);
        dfs(root->right,dequ,found,p);
        dequ.push_back(root->left);
        dfs(root->left,dequ,found,p);
        if(!found)
            dequ.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //    TreeNode* temp=root;
        bool pfound = false,qfound = false;
        deque<TreeNode*>quep,queq;
        quep.push_back(root);
        queq.push_back(root);
        dfs(root,quep,pfound,p);
        dfs(root,queq,qfound,q);
        int l = 0,r = 0;
        TreeNode* lca = nullptr;
        while(l<quep.size()&&r<queq.size()){
            if(quep[l]==queq[r]){
                lca = queq[l];
            }
            else{
                break;
            }
            l++,r++;
        }
        return lca;
    }
};








