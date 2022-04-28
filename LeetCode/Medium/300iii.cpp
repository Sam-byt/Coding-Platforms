class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int freq = 0;
        for(int i=1;i<n;i++){
            freq = 0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    freq = max(freq,ans[j]);
                }
            }
            ans[i]+=freq;
        }
        
        return *max_element(ans.begin(),ans.end());
    }
};
