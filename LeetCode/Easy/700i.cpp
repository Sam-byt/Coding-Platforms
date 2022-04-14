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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(!root)return nullptr;
        
        if(val == root->val)return root;
        
        
        
        TreeNode *lans = nullptr, *rans = nullptr;
        if(val < root->val)lans = searchBST(root->left,val);
        
        if(lans)return lans;
        
        if(val > root->val)rans = searchBST(root->right,val);
        
        return rans;
        
    }
};
