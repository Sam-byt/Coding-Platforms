class Solution {
    unordered_set<string>uset;
private:
    void solve(int i,vector<int>&nums,vector<vector<int>>&ans){
        if(i>=nums.size()){
            string s = ""; 
            for(auto k:nums){
                char c = k<0?k+21:k;
                s.push_back(c);
            }
            if(uset.find(s)==uset.end()){
                uset.insert(s);
                    ans.push_back(nums);
            }
        }
        
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        uset.clear();
        vector<vector<int>>ans;
        solve(0,nums,ans);
        
        return ans;
        
    }
};
