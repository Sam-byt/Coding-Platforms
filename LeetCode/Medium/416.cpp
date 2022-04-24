class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        else{
            sum>>=1;
            vector<bool>prev(sum+1,false),curr(sum+1);
            prev[0] = true;
            int n = nums.size();
            
            for(int i=1; i<n+1; i++){
                for(int j=0; j<sum+1; j++){
                    if(j == 0)curr[j] = true;
                    else curr[j] = nums[i-1]<=j?prev[j-nums[i-1]] || prev[j] : prev[j];
                }
                prev = curr;
            }
            return prev[sum];
        }
    }
};
