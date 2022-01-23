class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(abs(target)>sum  || (sum+target)&1)return 0;
        
        int s = (sum + abs(target))/2;
        
        int t[21][1001];
        
        
        
        
        int n =nums.size();
        
        for(int i= 0;i<s+1;i++)t[0][i] = 0;
        for(int i=0; i<n+1 ; i++)t[i][0] = 1;
        
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<s+1;j++)
            {
                t[i][j] = nums[i-1]<=j? t[i-1][j]+ t[i-1][j - nums[i-1]] : t[i-1][j];
            }
        }
        
        
        return t[n][s];
            
        
    }
};
