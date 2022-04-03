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
    
    void solve(TreeNode* root,int depth, int & max_depth){
        if(!root)return;
        
        if(isLeaf(root)){
            depth++;
            max_depth = max(depth,max_depth);
            return;
        }
        
        depth++;
        solve(root->left,depth,max_depth);
        solve(root->right,depth,max_depth);
        depth--;
        
    }
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        solve(root,0,max_depth);
        return max_depth;
        
    }
};
