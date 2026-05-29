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

class Codec {
public:
    string encode;
    void dfs(TreeNode* root){
        if(!root){
            encode+="n,";
            return;
        }
        if(root->left){
            encode+=to_string(root->left->val);
            encode+=',';
        }
        // else{
        //     encode+='n,';
        // }
        dfs(root->left);
        if(root->right){
            encode+=to_string(root->right->val);
            encode+=',';
        }
        // else{
        //     encode+='n,';
        // }
        dfs(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "n";
        encode += to_string(root->val);
        encode+=',';
        dfs(root);
        encode.pop_back();
        return encode;
    }
    pair<int,int> getNum(string data,int idx){
        int num = 0;
        int i = idx;
        int isnegative = 1;
        if(data[idx]=='-'){
            isnegative = -1;
            i++;
        }
        
        for(;i<data.size()&&data[i]!=',';i++){
            if(data[i]=='n'){
                num = -1001;
                i++;
                break;
            }
            num*=10;
            num+=data[i]-'0';
        }
        return{num * isnegative,i};
    }
    void dfsBuildTree(TreeNode*& root,string& data,int& idx){
        if(idx>=data.size())
            return;
        auto num = getNum(data,idx);
        if(num.first!=-1001)
        {
            root = new TreeNode(num.first);
            idx = num.second;
        }
        idx++;
        if(!root)
        {   idx++;
            return;
        }
        dfsBuildTree(root->left,data,idx);
        dfsBuildTree(root->right,data,idx);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        int idx =0;
        dfsBuildTree(root,data,idx);
        return root;
    }
};







