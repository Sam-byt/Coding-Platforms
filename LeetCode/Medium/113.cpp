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
    
    inline bool isLeaf(TreeNode* root){return !(root->left or root->right);}
    
    
    
    void solve(TreeNode* root, int target, vector<vector<int>>&ans, vector<int>v){
        if(!root)return;
        
        if(isLeaf(root)){
            v.push_back(root->val);
            int sum = accumulate(v.begin(),v.end(),0);
            if(sum == target)ans.push_back(v);
            return;
        }
        
        v.push_back(root->val);
        solve(root->left,target,ans,v);
        solve(root->right,target,ans,v);
        v.pop_back();
        
        
        
        
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(root,targetSum,ans,v);
        return ans;
        
        
    }
};
