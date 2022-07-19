class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prevSum;
        int ans = 0, currSum =0;
        for(auto i : nums){
            currSum += i;
            if(currSum == k)ans++;
            if(prevSum.find(currSum - k) != prevSum.end())ans+=prevSum[currSum-k];
            prevSum[currSum]++;
        }
        return ans;
    }
};
