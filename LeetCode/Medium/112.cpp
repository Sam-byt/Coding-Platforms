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
    
    bool solve(TreeNode* root,int target,vector<int>v){
        if(!root)return false;
        
        if(isLeaf(root)){
            v.push_back(root->val);
            if(accumulate(v.begin(),v.end(),0) == target)return true;
        }
        
        v.push_back(root->val);
        if(solve(root->left,target,v) or solve(root->right,target,v))return true;
        v.pop_back();
        return false;
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        return solve(root,targetSum,v);
        
    }
};
