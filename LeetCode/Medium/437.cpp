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

#define ll long long
class Solution {
private:
    void solve(TreeNode* root, int target, vector<int>path, int &cnt){
        if(!root)return;
        
        path.push_back(root->val);
        
        solve(root->left,target,path,cnt);
        solve(root->right,target,path,cnt);
        
        
        int n = path.size();
        ll sum = 0;
        for(int i = n-1; i>=0; i--){
            sum += path[i];
            if(sum == target)cnt++;
        }
        
        path.pop_back();
    }
    
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        vector<int>path;
        solve(root,targetSum,path,cnt);
        return cnt;    
        
    }
};
