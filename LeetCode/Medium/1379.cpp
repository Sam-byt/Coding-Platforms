/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode * solve(TreeNode *root, TreeNode *target){
        if(!root)return nullptr;
        
        if(root->val == target->val)return root;
        
        TreeNode *lans = solve(root->left,target);
        if(lans)return lans;
        return solve(root->right,target);
        
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(cloned,target);
    }
};
