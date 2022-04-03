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
private:
    bool isLeaf(TreeNode* root){
        return !(root->left || root->right);
    }
    
    void solve(TreeNode* root,vector<string> &ans,string s){
        if(!root)return;
        if(isLeaf(root)){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
       
        s += to_string(root->val);
        solve(root->left,ans,s+"->");
        solve(root->right,ans,s+"->");
        s.pop_back();
        
        
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        solve(root,ans,"");
        return ans;
    }
};
