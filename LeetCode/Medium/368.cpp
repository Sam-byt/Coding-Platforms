class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1),hash(n);
        
        int high = 1, index = 0;
        
        
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>high){
                high = dp[i];
                index = i;
            }
        }
        
        
        vector<int>ans;
        
        ans.push_back(nums[index]);
        
        while(hash[index] != index){
            index = hash[index];
            ans.push_back(nums[index]);
        }
        
        return ans;
    }
};
