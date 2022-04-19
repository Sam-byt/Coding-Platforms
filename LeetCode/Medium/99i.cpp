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
    void solve(TreeNode *root, vector<int>v , int &i){
        if(!root)return;
        
        solve(root->left,v,i);
        if(root->val != v[i])root->val = v[i];
        i++;
        solve(root->right,v,i);
    }
    
    void inorder(TreeNode *root, vector<int>&v){
        if(!root)return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int i=0;
        solve(root,v,i);
        
        
    }
};
