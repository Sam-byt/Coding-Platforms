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
private :
    inline bool isLeaf(TreeNode *root){return !(root->left or root->right);}
    
    void solve(TreeNode* root,int sum, int &ans){
        if(!root)return;
        
        if(isLeaf(root)){
            sum = sum*10 + root->val;
            ans += sum;
            return;
        }
        
        sum = sum*10 + root->val;
        
        solve(root->left,sum,ans);
        solve(root->right,sum,ans);
        
        sum = (sum - root->val)/10;
    }
public:
    int sumNumbers(TreeNode* root) {
        
        int ans = 0;
        
        solve(root,0,ans);
        
        return ans;
        
    }
};
