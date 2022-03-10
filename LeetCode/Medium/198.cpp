class Solution {
public:
    int rob(vector<int>& nums) {
        
        int prev1=0,prev2=0,curr =0;
        
        for(int i=1;i<=nums.size();i++)
        {
            curr = max(prev1,nums[i-1]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};
