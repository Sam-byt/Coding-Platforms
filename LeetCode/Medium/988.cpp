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
    inline bool isLeaf(TreeNode * root){return !(root->left or root->right);}
    
    
    void solve(TreeNode * root, string s, string &ans){
        if(!root)return;
        
        if(isLeaf(root)){
            s.push_back(root->val + 97);
            if(ans == "")ans = s;
            else{
                string temps = s, tempans = ans;
                reverse(temps.begin(),temps.end());
                reverse(tempans.begin(),tempans.end());
                
                if(lexicographical_compare(temps.begin(),temps.end(),tempans.begin(),tempans.end()))ans = s;
            }
        }
        
        s.push_back(root->val + 97);
        
        solve(root->left,s,ans);
        solve(root->right,s,ans);
        
        s.pop_back();
        
        
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        
        string ans;
        
        solve(root,"",ans);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
