class Solution {
    
    
private:
    
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int>v, int n)
    {
        if(n>=nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        
        solve(nums,ans,v,n+1);
        
        v.push_back(nums[n]);
        solve(nums,ans,v,n+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        vector<vector<int>> ans;
        
        vector<int> v;
        
        
        int n = 0;
        
        solve(nums,ans,v,n);
        
        return ans;
        
        
        
    }
};
