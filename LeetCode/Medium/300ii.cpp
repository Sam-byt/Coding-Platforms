class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+1,0),curr(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--)
                curr[j+1] = j<0?max(1+next[i+1],next[j+1]):(nums[i]>nums[j]?max(1+next[i+1],next[j+1]):next[j+1]); 
            next = curr;
        }
        
        return next[0];
    }
};
